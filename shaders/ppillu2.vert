/*******************************************************************************/
/*
 * Author: Ing. Jose Larios Delgado.
 * Project:  glsl shaders implementation with OpenSceneGraph.
 * Institutions: DGSCA, UNAM, Virtual Reality Department.
 * Description: Bump Mapping shader in OSG.   
 */
/*******************************************************************************/


varying vec3 lightVec;/*!< Light position vector passed to the fragment program.*/ 
varying vec3 eyeVec;/*!< Eye vector passed to the fragment program.*/
varying vec2 texCoord;/*!< Texture coordinates passed to the fragment program.*/

attribute vec3 vTangent;/*!< Tangent space vector.*/

uniform vec3 lightdir;
//varying vec3 LightDir;
					 
//!Main function.
/*!
   Calculates the necessary data to use in the fragment shader, light position, eye vector
   and texture coordinates.
*/
void main(void)
{
	gl_Position = ftransform();
	texCoord = gl_MultiTexCoord0.xy*vec2(-0.0009, -0.0009);
	
	vec3 n = normalize(gl_NormalMatrix * gl_Normal);
	vec3 t = normalize(gl_NormalMatrix * vTangent);
	vec3 b = cross(n, t);
	
	vec3 vVertex = vec3(gl_ModelViewMatrix * gl_Vertex);
	vec3 tmpVec = gl_LightSource[0].position.xyz - vVertex;
	//vec3 tmpVec = lightdir;
	
	//mat3 rotmat = mat3(t,b,n);
    //LightDir = rotmat * normalize(lightdir);
    //normalize(LightDir);

	lightVec.x = dot(tmpVec, t);
	lightVec.y = dot(tmpVec, b);
	lightVec.z = dot(tmpVec, n);

	tmpVec = -vVertex;
	eyeVec.x = dot(tmpVec, t);
	eyeVec.y = dot(tmpVec, b);
	eyeVec.z = dot(tmpVec, n);
}