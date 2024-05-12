# NEXA ROBOTICS 

## Descripción del Proyecto
Presentamos a Neit, un robot guía turístico diseñado para fomentar la educación sobre el mundo animal en los visitantes de zoológicos. Neit mejora la experiencia de visita al interactuar de forma "humana" e interactiva, reconociendo el estado de los animales en sus hábitats y reaccionando con frases y sonidos personalizados según la situación.

### Objetivo
Crear una experiencia educativa enriquecedora y dinámica que atraiga a visitantes de todas las edades, utilizando tecnología de punta para la interacción personalizada con información del mundo animal.

## Gestión del Repositorio
- **Rama MAIN**: Rama principal con código siempre listo para producción.
- **Rama SprintX**: Creada para cada sprint del proyecto.
- **Ramas de características/tareas**: Para desarrollo detallado de cada tarea.

## Equipo
- **Técnico**: Zaida, Carles (Diseñadores), Pepe (Control de Calidad)
- **Comercial**: Arnau y Chen
- **Administración**: Zaida y Arnau

## Socios y Mentores
- **Socio Clave**: UPV
- **Mentores**: Profesores de la UPV
- **Inspiración**: BostonDynamics, PAL Robotics

## Principios de Gobernanza
- Equivalencia
- Transparencia
- Responsabilidad
- Mejora continua

## Funcionalidades del Robot
- **Reconocimiento de Estado Animal**: Neit puede identificar si los animales están durmiendo, comiendo o activos, y ajusta sus interacciones en consecuencia.
- **Interacción por Voz**: El robot tiene capacidad de reconocer comandos de voz relacionados con animales específicos (leones, monos, jirafas) y navega hacia ellos.
- **Movimiento Autónomo en el Zoológico**: Utiliza ROS2 para la navegación y el mapeo del recinto, proporcionando tours autónomos a través del zoológico.

## Guía de Instalación y Ejecución
### Pruebas
Para ejecutar pruebas, sitúate en la carpeta `proy_nexa_service` y ejecuta:
python3 -m pytest -s -v

### Movimiento Real en Web
Ejecutar el servicio con el archivo `iniciar_servicio.sh` ubicado en la carpeta `comandos` del Servidor.

### Navegación a un Punto
- *Dentro de la máquina virtual de ubuntu*
1. Terminal 1:
ros2 launch my_world turtlebot3_my_world.launch.py
2. Terminal 2:
ros2 launch proy_nexa_nav2_system proy_nexa_tb3_sim_nav2.launch.py
3. Terminal 3:
- "repositorio2"es el nombre de nuestro repositorio, así que cambiarlo por el nombre que le hayáis puesto.
ros2 service call /map_server/load_map nav2_msgs/srv/LoadMap "{map_url: $HOME repositorio2/Robot/src/proy_nexa/proy_nexa_nav2_system/config/my_map.yaml}"
os2 run proy_nexa_nav2_system proy_nexa_initial_pose_pub
ros2 launch proy_nexa_action proy_nexa_action_client.launch.py
---

