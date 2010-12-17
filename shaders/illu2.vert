varying vec3 lightVec; 
varying vec3 eyeVec;
varying vec2 texCoord; 
varying vec3 normal;
					 

void main(void)
{
	gl_Position = ftransform();
        //gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	texCoord = gl_MultiTexCoord0.xy*vec2(0.005, 0.005);
	
	
	vec3 vVertex = vec3(gl_ModelViewMatrix * gl_Vertex);
	vec3 tmpVec = gl_LightSource[0].position.xyz - vVertex;


        lightVec = tmpVec;


	tmpVec = -vVertex;
        eyeVec = tmpVec;
        
        normal = normalize(gl_NormalMatrix * gl_Normal);


	
}