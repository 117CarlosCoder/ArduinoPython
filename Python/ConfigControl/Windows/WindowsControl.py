import serial
import serial.tools.list_ports
import time
import pyautogui 
import subprocess
import os

def manejar_mensaje(raw_string):
    """
    Procesa el mensaje recibido del puerto serial y ejecuta las acciones correspondientes.
    """
    if raw_string == "MOUSE_ARRIBA":
        print("Haciendo mouse arriba...")
        pyautogui.move(0, -30)  # Mueve el mouse 30 píxeles hacia arriba
    elif raw_string == "MOUSE_ABAJO":
        print("Haciendo mouse abajo...")
        pyautogui.move(0, 30)  # Mueve el mouse 30 píxeles hacia abajo
    elif raw_string == "ZOOM_IN":
        print("Haciendo zoom in...")
        pyautogui.hotkey('ctrl', '+')  # Simula Ctrl + +
    elif raw_string == "ZOOM_OUT":
        print("Haciendo zoom out...")
        pyautogui.hotkey('ctrl', '-')  # Simula Ctrl + -
    elif raw_string == "MOUSE_DERECHA":
        print("Haciendo mouse derecha...")
        pyautogui.move(30, 0)  # Mueve el mouse 30 píxeles hacia la derecha
    elif raw_string == "MOUSE_IZQUIERDA":
        print("Haciendo mouse izquierda...")
        pyautogui.move(-30, 0)  # Mueve el mouse 30 píxeles hacia la izquierda
    elif raw_string == "CLICK_IZQUIERDA":
        print("Haciendo click izquierdo...")
        pyautogui.click()  # Simula un click izquierdo
    elif raw_string == "TECLADO_PANTALLA":
        print("Abriendo teclado en pantalla...")
        os.startfile("C:\\Windows\\System32\\osk.exe")  # Aquí puedes simular abrir el teclado en pantalla si es necesario
    elif raw_string == "ACTIVAR_NARRADOR":
        print("Haciendo activar narrador...")
        pyautogui.hotkey('win', 'ctrl', 'enter ')  # Activa el narrador en Windows
    elif raw_string == "DESACTIVAR_NARRADOR":
        print("Haciendo desactivar narrador...")
        pyautogui.hotkey('win', 'ctrl', 'enter')  # Desactiva el narrador
    elif raw_string == "VOLUMEN_MAS":
        print("Subiendo volumen...")
        pyautogui.press('volumeup')  # Simula subir volumen, ajusta si es necesario
    elif raw_string == "VOLUMEN_MENOS":
        print("Bajando volumen...")
        pyautogui.press('volumedown')  # Simula bajar volumen
    elif raw_string == "CAMBIAR_VENTANA":
        print("Cambiando ventana...")
        pyautogui.hotkey('alt', 'tab')  # Cambia entre ventanas
    elif raw_string == "ABRIR_CHROME":
        print("Abriendo Chrome...")
        pyautogui.hotkey('C:\Program Files\Google\Chrome\Application\chrome.exe')  # Abre una nueva ventana de incógnito en Chrome
    elif raw_string == "ABRIR_TERMINAL":
        print("Abriendo terminal...")
        pyautogui.hotkey('win', 'r')  # Abre el cuadro de diálogo "Ejecutar"
        pyautogui.write('cmd')  # Escribe 'cmd' para abrir el terminal
        pyautogui.press('enter')  # Presiona Enter
    elif raw_string == "ABRIR_VSCODE":
        print("Abriendo Visual Studio Code...")
        subprocess.Popen(['C:\\path\\to\\your\\vscode.exe'])  # Cambia esta ruta a la de tu Visual Studio Code
    elif raw_string == "ABRIR_WORD":
        print("Abriendo Microsoft Word...")
        pyautogui.hotkey('win', 'r')  # Abre el cuadro de diálogo "Ejecutar"
        pyautogui.write('winword')  # Escribe 'winword' para abrir Word
        pyautogui.press('enter')  # Presiona Enter
    elif raw_string == "ABRIR_YOUTUBE":
        print("Abriendo YouTube en Microsoft Edge...")
        pyautogui.hotkey('win', 'r')  # Abre el cuadro de diálogo "Ejecutar"
        pyautogui.write('msedge')  # Escribe 'msedge' para abrir Microsoft Edge
        pyautogui.press('enter')  # Presiona Enter
        time.sleep(1)  # Espera un momento para que Edge se abra
        pyautogui.write('https://www.youtube.com')  # Escribe la URL de YouTube
        pyautogui.press('enter')  # Presiona Enter
    elif raw_string == "ABRIR_CORTANA":
        print("Abriendo Cortana...")
        pyautogui.hotkey('win')  # Abre el menú de inicio
        time.sleep(1)  # Espera un momento para que se abra
        pyautogui.write('Cortana')  # Escribe 'Cortana'
        pyautogui.press('enter')  # Presiona Enter
    elif raw_string == "SCROLL_ARRIBA":
        print("Haciendo scroll hacia arriba...")
        pyautogui.scroll(100)  # Desplaza hacia arriba
    elif raw_string == "SCROLL_ABAJO":
        print("Haciendo scroll hacia abajo...")
        pyautogui.scroll(-100)  # Desplaza hacia abajo
    elif raw_string == "APAGAR_SISTEMA":
        print("Apagar Sistema...")
        subprocess.call(['shutdown', '/s', '/t', '0'])

    else:
        print(f"Comando no reconocido: {raw_string}")

def encontrar_puerto_arduino():
    """
    Busca el puerto de un dispositivo Arduino conectado.
    """
    puertos = list(serial.tools.list_ports.comports())
    for p in puertos:
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
