# Actividad 4

#### Steven Josue González Monroy  - 201903974

Proceso de craeción de un systemd unit de tipo servicio que ejecuta un script de bash que muestra la fecha actual del sistema.

## Instalación

### Paso 1: Creación del script

1. En '/usr/local/bin/' crear un archivo .sh con el siguiente contenido:

    ```bash
    #!/bin/bash

    while true; do
        echo "Hola, fecha actual: $(date)"
        sleep 1
    done
    ```

2. Conceder permisos de ejecución al script con el siguiente comando:

    ```bash
    sudo chmod +x /usr/local/bin/actividad4.sh
    ```

### Paso 2: Crear el servicio Systemd Unit

1. Crear un archivo .service en la ruta /etc/systemd/system/ con el siguiente contenido:

    ```ini
    [Unit]
    Description=Imprime un saludo y la fecha actual 
    After=network.target

    [Service]
    ExecStart=/usr/local/bin/actividad4.sh
    Restart=always
    User=nobody
    Group=nogroup

    [Install]
    WantedBy=multi-user.target
    ```

### Paso 3: Habilitar y ejecutar el servicio

1. Reiniciamos systemd para applicar la configuración con el siguiente comando:

    ```bash
    sudo systemctl daemon-reload
    ```

2. Habilitamos el servicio para iniciarse en el arranque con el siguiente comando:

    ```bash
    sudo systemctl enable actividad4.service
    ```

3. Iniciamos el servicio por primera vez con el siguiente comando:

    ```bash
    sudo systemctl start actividad4.service
    ```

## Verificación de logs

* Para ver los logs mas recientes del servicio ejecutamos el siguiente comando:

    ```bash
    sudo journalctl -u actividad4.service -f
    ```

## Estado del servicio

* Para verificar el estado del servicio podemos usar el siguiente comando:


    ```bash
    sudo systemctl status actividad4.service
    ```
