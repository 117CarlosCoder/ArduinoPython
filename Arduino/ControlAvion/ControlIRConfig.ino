#include <IRremote.h>

// Pin del receptor IR
const int receiverPin = 11;

IRrecv irrecv(receiverPin);
decode_results results;

const unsigned long MOUSE_ARRIBA_CODES[] = {
  0x977332E0
};
const unsigned long MOUSE_ABAJO_CODES[] = {
  0x64BBC0B4
};
const unsigned long MOUSE_DERECHA_CODES[] = {
  0x8F7589CE, 0x8E51128, 0xC4985732, 0x8B906EA2, 0x94563D2, 0xCB6E2A, 
  0xC4985732, 0x56285122, 0x2042835E, 0xD0E107B4, 0x94563D2
};
const unsigned long MOUSE_IZQUIERDA_CODES[] = {
  0xABD1831A, 0x9B8EA10A, 0xB9754788, 0xA9BFDFB2, 0xC2961836
};

const unsigned long CLICK_IZQUIERDA_CODES[] = {
  
};
const unsigned long VOLUMEN_MAS_CODES[] = {};
const unsigned long VOLUMEN_MENOS_CODES[] = {};
const unsigned long CAMBIAR_VENTANA_CODES[] = {
  
};

const unsigned long ABRIR_CHROME_CODES[] = {};
const unsigned long ABRIR_TERMINAL_CODES[] = {};
const unsigned long ABRIR_VSCODE_CODES[] = {};
const unsigned long ABRIR_CALENDARIO_CODES[] = {};
const unsigned long ABRIR_RELOJ_CODES[] = {};
const unsigned long SCROLL_ARRIBA_CODES[] = {
    
};

const unsigned long SCROLL_ABAJO_CODES[] = {
  
};

const unsigned long TECLADO_PANTALLA[] = {
  
};

const unsigned long ACTIVAR_NARRADOR[] = {
  
};

const unsigned long QUITAR_NARRADOR[] = {
  
};

const unsigned long ZOOM_IN_CODES[] = {
  0xD65D24E, 0x75A42FAA, 0xD5AEFF14, 0xC8B8C5AE
};

const unsigned long ZOOM_OUT_CODES[] = {
  0x487F233A, 0xBD8AE1FE, 0xAFF1F196, 0xADE04E2E, 0x7D3B5448, 0xADE04E2E
};

// Función para verificar si un código pertenece a un array de códigos
bool codigoEnArray(unsigned long codigo, const unsigned long* array, int tamano) {
  for (int i = 0; i < tamano; i++) {
    if (codigo == array[i]) {
      return true;
    }
  }
  return false;
}

// Función para procesar los códigos recibidos
void procesarCodigoIR(unsigned long codigo) {
  if (codigoEnArray(codigo, MOUSE_ARRIBA_CODES, sizeof(MOUSE_ARRIBA_CODES) / sizeof(MOUSE_ARRIBA_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("MOUSE_ARRIBA");
  } else if (codigoEnArray(codigo, MOUSE_ABAJO_CODES, sizeof(MOUSE_ABAJO_CODES) / sizeof(MOUSE_ABAJO_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("MOUSE_ABAJO");
  } else if (codigoEnArray(codigo, ZOOM_IN_CODES, sizeof(ZOOM_IN_CODES) / sizeof(ZOOM_IN_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ZOOM_IN");
  } else if (codigoEnArray(codigo, ZOOM_OUT_CODES, sizeof(ZOOM_OUT_CODES) / sizeof(ZOOM_OUT_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ZOOM_OUT");
  }else if (codigoEnArray(codigo, MOUSE_DERECHA_CODES, sizeof(MOUSE_DERECHA_CODES) / sizeof(MOUSE_DERECHA_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("MOUSE_DERECHA");
  }else if (codigoEnArray(codigo, MOUSE_IZQUIERDA_CODES, sizeof(MOUSE_IZQUIERDA_CODES) / sizeof(MOUSE_IZQUIERDA_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("MOUSE_IZQUIERDA");
  } else if (codigoEnArray(codigo, CLICK_IZQUIERDA_CODES, sizeof(CLICK_IZQUIERDA_CODES) / sizeof(CLICK_IZQUIERDA_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("CLICK_IZQUIERDA");
  }  else if (codigoEnArray(codigo, VOLUMEN_MAS_CODES, sizeof(VOLUMEN_MAS_CODES) / sizeof(VOLUMEN_MAS_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("VOLUMEN_MAS");
  } else if (codigoEnArray(codigo, VOLUMEN_MENOS_CODES, sizeof(VOLUMEN_MENOS_CODES) / sizeof(VOLUMEN_MENOS_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("VOLUMEN_MENOS");
  } else if (codigoEnArray(codigo, CAMBIAR_VENTANA_CODES, sizeof(CAMBIAR_VENTANA_CODES) / sizeof(CAMBIAR_VENTANA_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("CAMBIAR_VENTANA");
  } else if (codigoEnArray(codigo, TECLADO_PANTALLA, sizeof(TECLADO_PANTALLA) / sizeof(TECLADO_PANTALLA[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("TECLADO_PANTALLA");
  } else if (codigoEnArray(codigo, ACTIVAR_NARRADOR, sizeof(ACTIVAR_NARRADOR) / sizeof(ACTIVAR_NARRADOR[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ACTIVAR_NARRADOR");
  } else if (codigoEnArray(codigo, QUITAR_NARRADOR, sizeof(QUITAR_NARRADOR) / sizeof(QUITAR_NARRADOR[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("QUITAR_NARRADOR");
  }   else if (codigoEnArray(codigo, ABRIR_CHROME_CODES, sizeof(ABRIR_CHROME_CODES) / sizeof(ABRIR_CHROME_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ABRIR_CHROME");
  } else if (codigoEnArray(codigo, ABRIR_TERMINAL_CODES, sizeof(ABRIR_TERMINAL_CODES) / sizeof(ABRIR_TERMINAL_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ABRIR_TERMINAL");
  } else if (codigoEnArray(codigo, ABRIR_VSCODE_CODES, sizeof(ABRIR_VSCODE_CODES) / sizeof(ABRIR_VSCODE_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ABRIR_VSCODE");
  } else if (codigoEnArray(codigo, ABRIR_CALENDARIO_CODES, sizeof(ABRIR_CALENDARIO_CODES) / sizeof(ABRIR_CALENDARIO_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ABRIR_CALENDARIO");
  } else if (codigoEnArray(codigo, ABRIR_RELOJ_CODES, sizeof(ABRIR_RELOJ_CODES) / sizeof(ABRIR_RELOJ_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ABRIR_RELOJ");
  } else if (codigoEnArray(codigo, SCROLL_ARRIBA_CODES, sizeof(SCROLL_ARRIBA_CODES) / sizeof(SCROLL_ARRIBA_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("SCROLL_ARRIBA");
  } else if (codigoEnArray(codigo, SCROLL_ABAJO_CODES, sizeof(SCROLL_ABAJO_CODES) / sizeof(SCROLL_ABAJO_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("SCROLL_ABAJO");
  } else {
    Serial.print("Código IR desconocido: ");
    Serial.println(codigo, HEX);
  }
}

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Iniciar el receptor IR
}

void loop() {
  if (irrecv.decode(&results)) {
    
    if (results.value != 0xFB55006D) {
      procesarCodigoIR(results.value); 
    }

    irrecv.resume();
  }
}
