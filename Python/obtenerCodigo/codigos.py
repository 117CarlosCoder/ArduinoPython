import serial
import time

# Conectar al puerto serial de tu Arduino
try:
    arduino = serial.Serial('/dev/ttyACM0', 9600)  # Asegúrate de que este sea el puerto correcto para Windows
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

except KeyboardInterrupt:
    print("Programa terminado.")
finally:
    arduino.close()  # Cierra el puerto al final
