/*******************************************************************************/
/*
 * Author: Ing. Jose Larios Delgado.
 * Project:  glsl shaders implementation with OpenSceneGraph.
 * Institutions: DGSCA, UNAM, Virtual Reality Department.
 * Description: Ambient Occlusion shader in OSG, based on a RenderMonkey shader.   
 */
/*******************************************************************************/

uniform float time_scale;/*!< Time scale, higher values increases the rotation speed*/
uniform float time_0_2PI;/*!< Rotation angle in time function*/

// output variables
varying vec3 vTexCoord;/*!< CubeMap texture coordinates passed to the fragment shader*/

//!Main function.
/*!
   The shader obtains the texture coordinates for the CubeMap, then rotates them 
   along the Y axis, this coordinates are passed to the fragment shader.
*/
void main(void)
{

   vec4 rotPos = vec4(gl_Vertex.x, gl_Vertex.y, gl_Vertex.z, gl_Vertex.w);
   vec4 n2 = vec4(gl_Vertex.x, gl_Vertex.y, gl_Vertex.z, gl_Vertex.w);
   
   float time_mul_time_0_2PI  = time_scale*time_0_2PI;
   
   rotPos.x = dot(gl_Vertex.xyz, vec3( cos(time_mul_time_0_2PI), 0, sin(time_mul_time_0_2PI)));
   rotPos.z = dot(gl_Vertex.xyz, vec3(-sin(time_mul_time_0_2PI), 0, cos(time_mul_time_0_2PI)));

   gl_Position = gl_ProjectionMatrix * rotPos ;
   vTexCoord = gl_Vertex.xyz;
   
}
