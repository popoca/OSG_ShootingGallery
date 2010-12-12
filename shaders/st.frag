/*******************************************************************************/
/*
 * Author: Ing. Jose Larios Delgado.
 * Project:  glsl shaders implementation with OpenSceneGraph.
 * Institutions: DGSCA, UNAM, Virtual Reality Department.
 * Description: Ambient Occlusion shader in OSG, based on a RenderMonkey shader.   
 */
/*******************************************************************************/

uniform samplerCube DiffuseEnvironment;/*!< CubeMap texture.*/
uniform sampler2D AmbientOcclusion;/*!< Ambient occlusion texture.*/


// inputs from vertex shader
varying vec2 vTexCoord;/*!< Ambient occlusion map texture coordinates passed from the vertex program.*/
varying vec3 vRotNorm;/*!< Rotated normal passed from the vertex program.*/



void main(void)
{
 
  vec4 ambient = textureCube( DiffuseEnvironment, vRotNorm);

  float ambientOcclusion = texture2D(AmbientOcclusion, vTexCoord).r;

   gl_FragColor =  ambientOcclusion * ambient;
   
}
