import serial
import serial.tools.list_ports
import time
import subprocess
import os

def ejecutar_comando(script_name, use_sudo=False):
    """
    Ejecuta un comando con o sin privilegios de superusuario.
    """
    username = os.getlogin()
    command = f"su -c '{script_name}' {username}" if use_sudo else script_name
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    
    print(f"Ejecutando: {command}")
    return process  # Regresar el proceso en lugar de esperar a que termine

def manejar_mensaje(raw_string):
    """
    Procesa el mensaje recibido del puerto serial y ejecuta las acciones correspondientes.
    """
    if raw_string == "MOUSE_ARRIBA":
        print("Haciendo mosue arriba...")
        ejecutar_comando("sh ../../../Scripts/Linux/mouse_arriba.sh")
    elif raw_string == "MOUSE_ABAJO":
        print("Haciendo mouse abajo...")
        ejecutar_comando("sh ../../../Scripts/Linux/mouse_abajo.sh")
    elif raw_string == "ZOOM_IN":
        print("Haciendo zoom in...")
        ejecutar_comando("sh ../../../Scripts/Linux/zoom_control.sh zoom_in")
    elif raw_string == "ZOOM_OUT":
        print("Haciendo zoom out...")
        ejecutar_comando("sh ../../../Scripts/Linux/zoom_control.sh zoom_out")
    elif raw_string == "MOUSE_DERECHA":
        print("Haciendo mouse derecha...")
        ejecutar_comando("sh ../../../Scripts/Linux/mouse_derecha.sh")
    elif raw_string == "MOUSE_IZQUIERDA":
        print("Haciendo mouse izquierda...")
        ejecutar_comando("sh ../../../Scripts/Linux/mouse_izquierda.sh")
    elif raw_string == "CLICK_IZQUIERDA":
        print("Haciendo mouse izquierda...")
        ejecutar_comando("sh ../../../Scripts/Linux/click_izquierda.sh")
    elif raw_string == "TECLADO_PANTALLA":
        print("Haciendo teclado pantalla...")
        ejecutar_comando("sh ../../../Scripts/Linux/teclado_pantalla.sh")
    elif raw_string == "ACTIVAR_NARRADOR":
        print("Haciendo activar narrador..")
        #ejecutar_comando("sh ../../../Scripts/Linux/activar_narrador.sh")
    elif raw_string == "DESACTIVAR_NARRADOR":
        print("Haciendo activar narrador..")
        #ejecutar_comando("sh ../../../Scripts/Linux/desactivar_narrador.sh")
    elif raw_string == "VOLUMEN_MAS":
        print("Subiendo volumen...")
        command = "pactl set-sink-volume @DEFAULT_SINK@ +5%"
        result = subprocess.run(command, shell=True, capture_output=True, text=True)
        if result.returncode == 0:
            print(f"Comando ejecutado exitosamente: {result.stdout}")
        else:
            print(f"Error ejecutando el comando '{command}': {result.stderr}")

    elif raw_string == "ABRIR_WORD":
        print("Abriendo Libre Office..")
        ejecutar_comando("sh ../../../Scripts/Linux/libre_office.sh")

    elif raw_string == "VOLUMEN_MENOS":
        os.environ["PULSE_SERVER"] = f"unix:/run/user/{os.getuid()}/pulse/native"
        command = "pactl set-sink-volume @DEFAULT_SINK@ +5%"
        print(f"Ejecutando: {command}")
        print(os.environ['PATH'])

        
        result = subprocess.run(command, shell=True, capture_output=True, text=True)

        if result.returncode == 0:
            print(f"Comando ejecutado exitosamente: {result.stdout}")
        else:
            print(f"Error ejecutando el comando '{command}': {result.stderr}")

    elif raw_string == "CAMBIAR_VENTANA":
        print("Cambiando ventana...")
        ejecutar_comando("sh ../../../Scripts/Linux/cambiar_ventana.sh")
    elif raw_string == "ABRIR_CHROME":
        print("Abriendo Chrome...")
        ejecutar_comando("google-chrome", use_sudo=True)
    elif raw_string == "ABRIR_TERMINAL":
        print("Abriendo terminal...")
        ejecutar_comando("sh ../../../Scripts/Linux/abrir_terminal.sh", use_sudo=True)
    elif raw_string == "ABRIR_VSCODE":
        print("Abriendo Visual Studio Code...")
        ejecutar_comando("sh ../../../Scripts/Linux/abrir_vscode.sh", use_sudo=True)
    elif raw_string == "SCROLL_ARRIBA":
        print("Haciendo scroll hacia arriba...")
        ejecutar_comando("sh ../../../Scripts/Linux/scroll_arriba.sh")
    elif raw_string == "SCROLL_ABAJO":
        print("Haciendo scroll hacia abajo...")
        ejecutar_comando("sh ../../../Scripts/Linux/scroll_abajo.sh")
    else:
        print(f"Comando no reconocido: {raw_string}")

def encontrar_puerto_arduino():
    """
    Busca el puerto de un dispositivo Arduino conectado.
    """
    puertos = list(serial.tools.list_ports.comports())
    for p in puertos:
        # Aquí buscamos puertos que contengan "Arduino" en la descripción
        print(f"Puerto encontrado: {p.device}, Descripción: {p.description}")  # Para depuración
        if "Arduino" in p.description or "ACM" in p.device:
            return p.device
    return None

def conectar_arduino(baudrate=9600):
    """
    Conecta al puerto serial del Arduino, detectando automáticamente el puerto.
    """
    port = encontrar_puerto_arduino()
    if not port:
        print("No se encontró ningún dispositivo Arduino conectado.")
        exit(1)
    try:
        arduino = serial.Serial(port, baudrate)
        time.sleep(2)  # Espera para asegurar que la conexión esté lista
        print(f"Conectado al puerto {port} a {baudrate} bps")
        return arduino
    except serial.SerialException as e:
        print(f"Error al conectar con el puerto serial: {e}")
        exit(1)
        
def leer_mensajes(arduino):
    """
    Lee mensajes del puerto serial y los procesa.
    """
    username = os.getlogin()
   
    while True:
            try:
                if arduino.in_waiting > 0:
                    raw_string = arduino.readline().decode('utf-8').strip()
                    print(f"Mensaje recibido: {raw_string}")

                
                    manejar_mensaje(raw_string)
            except KeyboardInterrupt:
                print("Programa terminado por el usuario.")
                break
            except Exception as e:
                print(f"Error al leer o procesar el mensaje: {e}")

if __name__ == "__main__":
    arduino = conectar_arduino()
    try:
        leer_mensajes(arduino)
    finally:
        arduino.close()
        print("Conexión con el Arduino cerrada.")


def encontrar_puerto_arduino():
    """
    Encuentra el puerto al que está conectado el Arduino.
    """
    puertos = list(serial.tools.list_ports.comports())
    for p in puertos:
        if "Arduino" in p.description:
            return p.device
    return None