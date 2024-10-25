#include <IRremote.h>

const int receiverPin = 11; // Pin al que está conectado el receptor IR
IRrecv irrecv(receiverPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Iniciar el receptor IR
}

void loop() {
  if (irrecv.decode(&results)) {
   
     // Mostrar el código recibido en hexadecimal
    if(results.value != 0xFB55006D){
      Serial.print("Código IR recibido: ");
      Serial.println(results.value, HEX);

      // Verificar el código y enviar un mensaje específico
      // Códigos para hacer zoom in
      if (results.value == 0x20DF00FF) { // Reemplaza con el código IR para zoom in
        Serial.println("ZOOM_IN"); // Mensaje específico para hacer zoom in
      }
      // Códigos para hacer zoom out
      else if (results.value == 0x20DF807F) { // Reemplaza con el código IR para zoom out
        Serial.println("ZOOM_OUT"); // Mensaje específico para hacer zoom out
      }
      // Códigos para girar a la derecha
      else if (results.value == 0xCDE0F5E4 || results.value == 0x6F4866D4 ||
               results.value == 0xEA0151CC || results.value == 0xA49D8C6 ||
               results.value == 0x714625C0 || results.value == 0x8854F91E ||
               results.value == 0x8B4EA156 || results.value == 0x8AD3223B ||
               results.value == 0xC1BB1534 || results.value == 0x72695B74 ||
               results.value == 0xC9936E96 || results.value == 0xF97FA848 ||
               results.value == 0xA2C78E2B || results.value == 0x6F777F16 ||
               results.value == 0x2158532F || results.value == 0x6D556CB ||
               results.value == 0x62BACE7C || results.value == 0xD51B2D00 ||
               results.value == 0x97E8950E || results.value == 0xEA318ECE ||
               results.value == 0x5FBAD189 || results.value == 0x7FEC0968 ||
               results.value == 0xB4691298 || results.value == 0xA49FCB83 ||
               results.value == 0x20A6B32E || results.value == 0x4E4945AE ||
               results.value == 0xC7198EF8 || results.value == 0xE0AE206 ||
               results.value == 0xC4296AAB || results.value == 0x5B28A02 ||
               results.value == 0xD412324B || results.value == 0xDEF13644 ||
               results.value == 0xA209671B || results.value == 0x4C1730E9 ||
               results.value == 0xBEFD5B17 || results.value == 0xC8A8E14B ||
               results.value == 0xFCEAC09F || results.value == 0xC1A3F840 ||
               results.value == 0x2D85A623 || results.value == 0x5F4CAA1A ||
               results.value == 0xFD9337FC || results.value == 0x29951EFE ||
               results.value == 0x5857D264 || results.value == 0x25AC9AD1 ||
               results.value == 0xFAE80248 || results.value == 0x854CC851 ||
               results.value == 0xF13F6A17 || results.value == 0x248AE9B8 ||
               results.value == 0x9EC3BA85 || results.value == 0xCDE06BBC ||
               results.value == 0xF1AA80AD || results.value == 0x3BC47EC8 ||
               results.value == 0xBB31F70C || results.value == 0x164B1D26 ||
               results.value == 0xEF8F5F4F || results.value == 0xA2C2E40B ||
               results.value == 0x5C59616C || results.value == 0xB0A3AC2C ||
               results.value == 0x88F5ADAD || results.value == 0x949E317A ||
               results.value == 0x61256002 || results.value == 0x6898382D ||
               results.value == 0x3413E791 || results.value == 0xE50EAF33 ||
               results.value == 0x7565D82B || results.value == 0xC38A92D5 ||
               results.value == 0xECB050CA || results.value == 0x3B9138CD ||
               results.value == 0x69DBBC3D || results.value == 0x22AE7A28 ||
               results.value == 0x1D18F3F6 || results.value == 0x82580AD0 ||
               results.value == 0x329667B || results.value == 0x1FBB7D55 ||
               results.value == 0x347A3059 || results.value == 0x6E4EE4B4 ||
               results.value == 0xC373F10 || results.value == 0x44ECFC07 ||
               results.value == 0x98AEB0C || results.value == 0x5C362B77 ||
               results.value == 0x4853D704 || results.value == 0xD4424C79 ||
               results.value == 0xE9ACA014 || results.value == 0x46172D8F ||
               results.value == 0x939180AA || results.value == 0xD56A2D8B ||
               results.value == 0xCD87E94 || results.value == 0x25AE7EE1 ||
               results.value == 0xEA0E5281 || results.value == 0x24AE7D4F ||
               results.value == 0xFFCBB42B7 || results.value == 0x45172BFA ||
               results.value == 0x4AB0F7B6 || results.value == 0x1410D334 ||
               results.value == 0x6CF9A640 || results.value == 0x1110CE7D ||
               results.value == 0x6709B16A || results.value == 0x6765B8B4 ||
               results.value == 0x168D088D || results.value == 0x6A4EFD51) {
        Serial.println("GIRO_DERECHA"); // Mensaje específico para girar a la derecha
      }
    }
    irrecv.resume(); // Reanudar el receptor para recibir el siguiente código
  }
}
