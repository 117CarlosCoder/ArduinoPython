#include <IRremote.h>

// Pin del receptor IR
const int receiverPin = 11;

IRrecv irrecv(receiverPin);
decode_results results;

const unsigned long MOUSE_ARRIBA_CODES[] = {
  0x20DF00FF
};
const unsigned long MOUSE_ABAJO_CODES[] = {
  0x20DF807F, 0x83F539DF, 0xBCBD452C, 0x169CDC1F,
  0xCB892CA5, 0x49B0F625, 0xB80CDF09, 0xB2C7EFE8, 0xB9A968E5
};
const unsigned long MOUSE_DERECHA_CODES[] = {
  0xBB500C12, 0x9E0A10FF, 0x524B32C3, 0x20DF40BF
};
const unsigned long MOUSE_IZQUIERDA_CODES[] = {
  0xCDE0F5E4, 0x20DFC03F
};

const unsigned long CLICK_IZQUIERDA_CODES[] = {
  0x20DF22DD
};
const unsigned long VOLUMEN_MAS_CODES[] = {0x20DFA956};
const unsigned long VOLUMEN_MENOS_CODES[] = {0x20DF58A7};
const unsigned long CAMBIAR_VENTANA_CODES[] = {
  0x20DF9C63
};

const unsigned long ABRIR_CHROME_CODES[] = {0x20DF8877};
const unsigned long ABRIR_TERMINAL_CODES[] = {0x20DF48B7};
const unsigned long ABRIR_VSCODE_CODES[] = {0x20DFC837};
const unsigned long ABRIR_CALENDARIO_CODES[] = {0x20DF28D7};
const unsigned long ABRIR_RELOJ_CODES[] = {0x20DFA857};
const unsigned long ABRIR_WORD_CODES[] = {0x20DF6897};
const unsigned long ABRIR_YOUTUBE_CODES[] = {0x20DFE817};
const unsigned long ABRIR_CORTANA_CODES[] = {0x20DF18E7};
const unsigned long SCROLL_ARRIBA_CODES[] = {
  0x20DFAA55  
};


const unsigned long APAGAR_CODES[] = {
  0x20DF10EF
};
const unsigned long SCROLL_ABAJO_CODES[] = {
  0x20DFEA15
};

const unsigned long TECLADO_PANTALLA[] = {
  0x20DFC23D
};

const unsigned long ACTIVAR_NARRADOR[] = {
  0x20DF7887
};

const unsigned long QUITAR_NARRADOR[] = {
  0x20DF708F
};

const unsigned long ZOOM_IN_CODES[] = {
  0x20DF2AD5
};

const unsigned long ZOOM_OUT_CODES[] = {
  0x20DFE21D
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
    
    if (results.value != 0xFB55006D) {
      procesarCodigoIR(results.value); 
    }

    irrecv.resume();
  }
}
