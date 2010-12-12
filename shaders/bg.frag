/*******************************************************************************/
/*
 * Author: Ing. Jose Larios Delgado.
 * Project:  glsl shaders implementation with OpenSceneGraph.
 * Institutions: DGSCA, UNAM, Virtual Reality Department.
 * Description: Ambient Occlusion shader in OSG, based on a RenderMonkey shader.   
 */
/*******************************************************************************/

uniform samplerCube Environment;/*!< CubeMap texture.*/


// input variables from the vertex shader
varying vec3 vTexCoord;/*!< CubeMap texture coordinates passed from the vertex shader.*/

//!Main function.
/*!
   Applies the CubeMap texture usin the texture coordinates calculated in the vertex program.
*/
void main(void)
{
     
     gl_FragColor =   textureCube(Environment, vTexCoord);
}
