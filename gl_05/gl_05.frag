#version 330 core

#define NUMBER_OF_POINT_LIGHTS 30

struct DirLight
{
    vec3 direction;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight
{
    float constant;
    float linear;
    float quadratic;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec3 vecColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D Texture0;
uniform sampler2D Texture1;
uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLight;
uniform vec3 pointLightsPosition[NUMBER_OF_POINT_LIGHTS];

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(vec3 pointLightPosition, PointLight pointLight, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    // Properties
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
    
    // Directional lighting
    vec3 result = CalcDirLight(dirLight, norm, viewDir);

    for (int i = 0; i < NUMBER_OF_POINT_LIGHTS; i++)
    {
        result += CalcPointLight(pointLightsPosition[i], pointLight, norm, FragPos, viewDir);
    }

    color = vec4(result, 1.0);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    
    // Combine results
    vec3 ambient = light.ambient * vec3(texture(Texture0, TexCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture(Texture0, TexCoord));
    vec3 specular = light.specular * spec * vec3(texture(Texture0, TexCoord));
    
    return (ambient + diffuse + specular);
}

vec3 CalcPointLight(vec3 pointLightPosition, PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(pointLightPosition - fragPos);
    
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    
    // Attenuation
    float distance = length(pointLightPosition - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    
    // Combine results
    vec3 ambient = light.ambient * vec3(texture(Texture0, TexCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture(Texture0, TexCoord));
    vec3 specular = light.specular * spec * vec3(texture(Texture0, TexCoord));
    
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    
    return (ambient + diffuse + specular);
}