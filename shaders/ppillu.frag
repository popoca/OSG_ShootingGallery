/*******************************************************************************/
/*
 * Author: Ing. Jose Larios Delgado.
 * Project:  glsl shaders implementation with OpenSceneGraph.
 * Institutions: DGSCA, UNAM, Virtual Reality Department.
 * Description: Bump Mapping shader in OSG.   
 */
/*******************************************************************************/


varying vec3 lightVec;/*!< Light position vector passed from the vertex program.*/ 
varying vec3 eyeVec;/*!< Eye vector passed from the vertex program.*/
varying vec2 texCoord;/*!< Texture coordinates passed from the vertex program.*/

uniform sampler2D colorMap;/*!< Difusse map texture.*/
uniform sampler2D normalMap;/*!< Normal map texture.*/
uniform sampler2D ambientO;/*!< Ambient occlusion texture.*/
//uniform float invRadius;/*!< Attenuation radius.*/

//!Main function.
/*!
   Calculates per pixel illumination for a point light with attenuation and the color
   components for the bump map effect.  
*/
void main (void)
{

	//vec3 lVec = normalize(lightVec);
	vec3 vVec = normalize(eyeVec);
	
	float distSqr = dot(lightVec, lightVec);
	//float att = clamp(1.0 - invRadius * sqrt(distSqr), 0.0, 1.0);
	vec3 lVec = lightVec * inversesqrt(distSqr);
	
	vec4 base = texture2D(colorMap, texCoord);
	
	vec3 bump = normalize( texture2D(normalMap, texCoord).xyz * 2.0 - 1.0);
	
	vec4 ao = texture2D(ambientO, texCoord);

	vec4 vAmbient = gl_LightSource[0].ambient * gl_FrontMaterial.ambient;

	float diffuse = max( dot(lVec, bump), 0.0 );
	
	vec4 vDiffuse = gl_LightSource[0].diffuse * gl_FrontMaterial.diffuse * 
					diffuse;	

	float specular = pow(clamp(dot(reflect(-lVec, bump), vVec), 0.0, 1.0), 
	                 gl_FrontMaterial.shininess );
	
	vec4 vSpecular = gl_LightSource[0].specular * gl_FrontMaterial.specular * 
					 specular;	
	
	gl_FragColor = ( vAmbient*base + 
					 vDiffuse*base + 
					 vSpecular)
					 * ao;
					 //* att;
}