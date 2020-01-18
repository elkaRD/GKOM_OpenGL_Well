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
//uniform vec3 pointLightsPosition[NUMBER_OF_POINT_LIGHTS];
uniform vec3 pointLightsPosition0;
uniform vec3 pointLightsPosition1;
uniform vec3 pointLightsPosition2;
uniform vec3 pointLightsPosition3;
uniform vec3 pointLightsPosition4;
uniform vec3 pointLightsPosition5;
uniform vec3 pointLightsPosition6;
uniform vec3 pointLightsPosition7;
uniform vec3 pointLightsPosition8;
uniform vec3 pointLightsPosition9;
uniform vec3 pointLightsPosition10;
uniform vec3 pointLightsPosition11;
uniform vec3 pointLightsPosition12;
uniform vec3 pointLightsPosition13;
uniform vec3 pointLightsPosition14;
uniform vec3 pointLightsPosition15;
uniform vec3 pointLightsPosition16;
uniform vec3 pointLightsPosition17;
uniform vec3 pointLightsPosition18;
uniform vec3 pointLightsPosition19;
uniform vec3 pointLightsPosition20;
uniform vec3 pointLightsPosition21;
uniform vec3 pointLightsPosition22;
uniform vec3 pointLightsPosition23;
uniform vec3 pointLightsPosition24;
uniform vec3 pointLightsPosition25;
uniform vec3 pointLightsPosition26;
uniform vec3 pointLightsPosition27;
uniform vec3 pointLightsPosition28;
uniform vec3 pointLightsPosition29;

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(vec3 pointLightPosition, PointLight pointLight, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    // Properties
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
    
    // Directional lighting
    vec3 result = CalcDirLight(dirLight, norm, viewDir);
    /*
    for (int i = 0; i < NUMBER_OF_POINT_LIGHTS; i++)
    {
        result += CalcPointLight(pointLightsPosition[i], pointLight, norm, FragPos, viewDir);
    }*/
    //Position lighting
    result += CalcPointLight(pointLightsPosition0, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition1, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition2, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition3, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition4, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition5, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition6, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition7, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition8, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition9, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition10, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition11, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition12, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition13, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition14, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition15, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition16, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition17, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition18, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition19, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition20, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition21, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition22, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition23, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition24, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition25, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition26, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition27, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition28, pointLight, norm, FragPos, viewDir);
    result += CalcPointLight(pointLightsPosition29, pointLight, norm, FragPos, viewDir);

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