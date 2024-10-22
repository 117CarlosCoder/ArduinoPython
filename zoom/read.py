import serial
import time
import subprocess

# Conectar al puerto serial de tu Arduino
try:
    arduino = serial.Serial('/dev/ttyACM2', 9600)  # Asegúrate de que este sea el puerto correcto
    time.sleep(2)  # Espera para asegurar que la conexión esté lista
except serial.SerialException as e:
    print(f"Error al conectar con el puerto serial: {e}")
    exit(1)

try:
    with open("codes.txt", "a") as file:  # Abre el archivo en modo append
        while True:
            # Leer una línea del puerto serial
            if arduino.in_waiting > 0:
                raw_string = arduino.readline().decode('utf-8').strip()
                print(f"Mensaje recibido: {raw_string}")

                # Guardar el código en el archivo
                file.write(f"{raw_string}\n")

                # Verificar si el mensaje es "ZOOM_IN"
                if raw_string == "ZOOM_IN":
                    print("Haciendo zoom in...")
                    # Llama al script de zoom_control.sh para hacer zoom in
                    result = subprocess.run("/home/carloslopez/scripts/zoom_control.sh zoom_in", shell=True, capture_output=True, text=True)

                    if result.returncode != 0:
                        print("Error ejecutando el comando:", result.stderr)
                    else:
                        print("Comando ejecutado exitosamente:", result.stdout)

                # Verificar si el mensaje es "ZOOM_OUT"
                elif raw_string == "ZOOM_OUT":
                    print("Haciendo zoom out...")
                    # Llama al script de zoom_control.sh para hacer zoom out
                    result = subprocess.run("/home/carloslopez/scripts/zoom_control.sh zoom_out", shell=True, capture_output=True, text=True)

                    if result.returncode != 0:
                        print("Error ejecutando el comando:", result.stderr)
                    else:
                        print("Comando ejecutado exitosamente:", result.stdout)

except KeyboardInterrupt:
    print("Programa terminado.")
finally:
    arduino.close()  # Cierra el puerto al final
