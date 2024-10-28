#include <IRremote.h>

// Pin del receptor IR
const int receiverPin = 11;

IRrecv irrecv(receiverPin);
decode_results results;

unsigned long ultimoCodigo = 0;
unsigned long tiempoUltimoCodigo = 0;
const unsigned long intervaloFiltrado = 200; 

const unsigned long MOUSE_ARRIBA_CODES[] = {
  0x9EB92
};
const unsigned long MOUSE_ABAJO_CODES[] = {
  0x5EB92
};
const unsigned long MOUSE_DERECHA_CODES[] = {
  0x3EB92
};
const unsigned long MOUSE_IZQUIERDA_CODES[] = {
  0xDEB92
};

const unsigned long CLICK_IZQUIERDA_CODES[] = {
  0xD0B92
};
const unsigned long VOLUMEN_MAS_CODES[] = {0x490};
const unsigned long VOLUMEN_MENOS_CODES[] = {0xC90};
const unsigned long CAMBIAR_VENTANA_CODES[] = {
  0xD8B92
};

const unsigned long ABRIR_CHROME_CODES[] = {0xB92};
const unsigned long ABRIR_TERMINAL_CODES[] = {0x80B92};
const unsigned long ABRIR_VSCODE_CODES[] = {0x40B92};
const unsigned long ABRIR_CALENDARIO_CODES[] = {0xC0B92};
const unsigned long ABRIR_RELOJ_CODES[] = {0x20B92};
const unsigned long ABRIR_WORD_CODES[] = {0xA0B92};
const unsigned long ABRIR_YOUTUBE_CODES[] = {0x60B92};
const unsigned long ABRIR_CORTANA_CODES[] = {0xE0B92};
const unsigned long SCROLL_ARRIBA_CODES[] = {
  0x14B92 
};


const unsigned long APAGAR_CODES[] = {
  0xA8B92
};
const unsigned long SCROLL_ABAJO_CODES[] = {
  0xC6B92
};

const unsigned long TECLADO_PANTALLA[] = {
  0x58B92
};

const unsigned long ACTIVAR_NARRADOR[] = {
  0x70B92
};

const unsigned long QUITAR_NARRADOR[] = {
  0x2AB92
};

const unsigned long ZOOM_IN_CODES[] = {
  0x28B46
};

const unsigned long ZOOM_OUT_CODES[] = {
  0x3AB92
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
  } else if (codigoEnArray(codigo, ABRIR_WORD_CODES, sizeof(ABRIR_WORD_CODES) / sizeof(ABRIR_WORD_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ABRIR_WORD");
  } else if (codigoEnArray(codigo, ABRIR_YOUTUBE_CODES, sizeof(ABRIR_YOUTUBE_CODES) / sizeof(ABRIR_YOUTUBE_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ABRIR_YOUTUBE");
  } else if (codigoEnArray(codigo, ABRIR_CORTANA_CODES, sizeof(ABRIR_CORTANA_CODES) / sizeof(ABRIR_CORTANA_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("ABRIR_CORTANA");
  } else if (codigoEnArray(codigo, SCROLL_ARRIBA_CODES, sizeof(SCROLL_ARRIBA_CODES) / sizeof(SCROLL_ARRIBA_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("SCROLL_ARRIBA");
  } else if (codigoEnArray(codigo, SCROLL_ABAJO_CODES, sizeof(SCROLL_ABAJO_CODES) / sizeof(SCROLL_ABAJO_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("SCROLL_ABAJO");
  }  else if (codigoEnArray(codigo, APAGAR_CODES, sizeof(APAGAR_CODES) / sizeof(APAGAR_CODES[0]))) {
    Serial.println(codigo, HEX);
    Serial.println("APAGAR_SISTEMA");
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
    if (results.value != ultimoCodigo || (millis() - tiempoUltimoCodigo > intervaloFiltrado)) {
      procesarCodigoIR(results.value);  
      ultimoCodigo = results.value;     
      tiempoUltimoCodigo = millis();    
    }
    irrecv.resume();  
  }
}
