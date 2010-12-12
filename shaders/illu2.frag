varying vec3 lightVec;
varying vec3 eyeVec;
varying vec2 texCoord;
varying vec3 normal;

uniform sampler2D colorMap;
uniform float invRadius;

void main (void)
{


	vec3 n = normalize(normal);
	vec3 vVec = normalize(eyeVec);
	float NdotL;
	
	
	//NdotL = max(dot(n,normalize(lightVec)),0.0);
	NdotL = dot(n,normalize(lightVec));
	vec4 fcolor;
	
	
	
	    float distSqr = dot(lightVec, lightVec);
		float att = clamp(1.0 - invRadius * sqrt(distSqr), 0.0, 1.0);
		vec3 lVec = lightVec * inversesqrt(distSqr);
		
		
	
		vec4 base = texture2D(colorMap, texCoord);
	

		vec4 vAmbient = gl_LightSource[0].ambient * gl_FrontMaterial.ambient;

	
		vec4 vDiffuse = gl_LightSource[0].diffuse * gl_FrontMaterial.diffuse * NdotL;	

	
		vec4 vSpecular = gl_LightSource[0].specular * gl_FrontMaterial.specular;
		
		fcolor = ( vAmbient*base + vDiffuse*base + vSpecular) * att ;
		fcolor.a = base.a;
	
	
	gl_FragColor = fcolor;

        
}