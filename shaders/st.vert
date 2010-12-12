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
varying vec2 vTexCoord;/*!< Ambient occlusion map texture coordinates passed to the fragment program.*/
varying vec3 vRotNorm;/*!< Rotated normal passed to the fragment program.*/

//!Main function.
/*!
   The shader calculates the texture coordinates for the CubeMap and Ambient occlusion map, then rotates 
   the CubeMap coordinates along the Y axis, both coordinates are passed to the fragment shader.
*/
void main(void)
{
   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

   vec3 Nworld = gl_NormalMatrix * gl_Normal; // Intrinsic argument ordering effectively multiplies by transpose of inverse view matrix
   
   // OpenGL Z is opposite of d3d z...we need to match d3d here since the maps presuppose d3d coordinate system.
   Nworld.z = -Nworld.z;

   float time_mul_time_0_2PI  = time_scale*time_0_2PI;
   

   // Rotate the normal back the other way so lighting is correct
   vRotNorm.x = dot(Nworld.xyz, vec3(cos(time_mul_time_0_2PI), 0, -sin(time_mul_time_0_2PI)));
   vRotNorm.y = Nworld.y;
   vRotNorm.z = dot(Nworld.xyz, vec3(sin(time_mul_time_0_2PI), 0,  cos(time_mul_time_0_2PI)));

   vTexCoord = vec2(gl_MultiTexCoord0.s, 1.0-gl_MultiTexCoord0.t);
   
}
