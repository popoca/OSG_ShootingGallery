OSG Shooting Gallery

A very horrible shooting game where you shoot some farm animals because apparently our teacher hates these. Done with as much passion and enthuasiasm as we're allowed to have on a innocent-killing game, feel free to contribute and help those animals out of the farm.

Details:

Design:

In every frame:
Animate
Sound
Collide
CheckLogic

He said:
Input
Sound
Effects
GameSim
SceneHandler

A level has:

Spawn order
Time limit
Speed modifiers for every enemy
Number of enemies
Logic, when all enemies are down, go to next level IF score is cool

Enemy has:

static number of enemies

speed
movement behavior
killing behavior
isVisible flag

Camera:
is static
can peek (optional)

Mouse:
has to be replaced

Shaders: particulas

Random things he said:
Modelos ya tienen su mapa cargado en la textura 0
Casa sin shader
Aplicar mapa de difusion transAO?
transparencia
ambient occlusion
zona de obstaculos
3 texturas cargadas para el relleno, maybe, con mapa de difusion, unidad textura 1
palos de la cerca aplicar difusion normal
tiene un mapa de normales, bump mapping

suelo con difusion, normal, ambient occlusion, aplicar detalle de decal.
canal alfa aplicado sobre el terreno

Pasto con transparencia

5 niveles
Cambio de secuencia de objetivos
Aumentar velocidad de objetivos con el paso de los niveles
Iniciar con teclado
Mira con el mouse
Boton izq pa disparar, derecho recarga 3 a 5 segundos
Objetivos moviles con el tiempo

Rectas, trayecto senoidal, regreso aleatorio
Disparos a 3 distancias, lejos, medio, cerca

entradas, sonidos para las entradas
efectos, shaders, 

Martin dijo:
pero con que pongas msh->BumpMappingShader(rNode4);