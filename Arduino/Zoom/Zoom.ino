#include <IRremote.h>

const int receiverPin = 11; // Pin al que está conectado el receptor IR
IRrecv irrecv(receiverPin);
decode_results results;

const unsigned long ignoredCodes[] = {
  0x1FB029A, 0x48E10806, 0xB0E7BAA4, 0x57029A6A, 0x727E17BC,
  0xA38507A6, 0x9E417EE2, 0x1449CA15, 0xFB498C3, 0x5B4425E4,
  0xAC7ADB6, 0x8D6FB9C7, 0x66D39B7B, 0x92C709D, 0xDC34457B,
  0xFC8691AF, 0xEDADEA39, 0xE50DCED4, 0x7EF90C6E, 0xB4DE524D,
  0x76AEAC05, 0xA0445D07, 0xC696EE46, 0xCAE7ED69, 0x3B54956C,
  0xC230D53B, 0xA4C14455, 0x1A6FABBB, 0x9733B65D, 0xBC06F846,
  0x1D4A365D, 0xF1E3FC2E, 0x6455F8BF, 0xEDFDBECB, 0xA00E90E8,
  0xF899D52F, 0x1DF495F, 0xA987FC5, 0xFF9A50FD, 0xE2F4D861,
  0x5E6CED0A, 0xBF0CC120, 0x5D5E69B9, 0xEDADEA39, 0xC059641,
  0x9EF6B491, 0xC34DC663, 0xD5F051DE, 0x35E930F, 0x9A82B0A9,
  0x7CE3EFB1, 0xCB22F271, 0xBCC77C0, 0x7E0E1A07, 0x5F283C32,
  0x3E2C0B, 0x22E86D24, 0xB2DE8CAC, 0x19A9A942, 0xD6F0536E,
  0xAD6FEE90, 0x8ED300DD, 0x837CBE1B, 0xA3486F6B, 0x55356491,
  0x60F595AE, 0x883EB747, 0xA5F5895E, 0x68A82DD2, 0x173EF834,
  0x79249898, 0x877C2CC7, 0x737BCD16, 0xE509776B, 0x8A5C2244,
  0x7660E196, 0xC7BF2771, 0x6693ABA, 0xC1B3E027, 0xBC0CBC68,
  0x4D7787B9, 0xE3C135B4, 0x80FA1A62, 0x4F964E1C, 0x415B1D58,
  0x5B38DD11, 0x960A41FF, 0x3CACF71B, 0xBF0CC121, 0x7F28348,
  0x17467689, 0x4B1CB02A, 0x216E564A, 0x10AC84F6, 0xE5AD0F58,
  0x1B8FF743, 0x7D77B72B, 0xA7922660, 0xA3E455ED, 0xBFB95332,
  0x309265C9, 0x4D4E832E, 0x3284E0F, 0xA1C2119A, 0x56CF2432,
  0xB2FCF7AB, 0x7CA2D107, 0xDF8DB370, 0xE09E7068, 0xBC0CBC68,
  0x5A795AB8, 0xB5EAAA3A, 0x70898927, 0x506FEBF, 0x29FEA370,
  0xFBC11712, 0x26439A66, 0xB264CF9C, 0xA1B37CD0, 0x4A70802D,
  0x5366FBA1, 0xA227FCE5, 0xAD609939, 0xF47C2A21, 0x2CBBE176,
  0x8669579D, 0xE9695C92, 0xA6E8F8A5, 0x5B38DD10, 0x35B87F4F,
  0x823CA1C8, 0xAA4A0E5F, 0xE002683D, 0x5D5F77FE, 0x81D2CBA6,
  0x3AA85A4, 0xD786EEF7, 0xF608D47D, 0x5D75A103, 0x72265137,
  0xF1E5F67E, 0x9CDBBDB8, 0xED8CF6AE, 0xDDE49D9, 0x60EC18AC,
  0xE5A90DB0, 0x2315D927, 0x6B763EDD, 0x25215AD0, 0x477142AE,
  0xC5B98D52, 0xB1A28CC7, 0x42088DFE, 0xF52A6ABB, 0xAE1D672F,
  0xEACFFD0A, 0x45C890EE, 0x1FED3835, 0x1249D3F3, 0xA2D334C0,
  0x71E5E362, 0x8645C38A, 0x41336A51, 0x6A1706D2, 0x3DEA070D,
  0x1BCE2642, 0x589F4364, 0x2CBBE175, 0x730BF2C7, 0x5929C5A0,
  0xDEE02AC2, 0x6B6D45AB, 0xC1D4EC0, 0x5013D250, 0x1149C55E,
  0x184C8A4, 0x1149C55E, 0xD9B28281, 0x1D4A365D, 0x75D96D86,
  0x8D6FB9C7, 0xBF0CC120, 0xF4486945, 0xE1744599, 0x5D0997F2,
  0xB38477B3, 0xE58CCA90, 0x83628501, 0xFAF9690A, 0xCC702606,
  0x59AB849D, 0x483C6759, 0x78152747, 0xBA7FDF73, 0xCD38DB96,
  0x4AE7ECF, 0xC7800124, 0x753CFAD, 0x4B28A09D, 0x98404BAF,
  0xFE5CC769, 0x1BA3376B, 0x26B07248, 0xB13C1133, 0x1449CA15,
  0xA63E5430, 0x9177F3F7, 0x280272E1, 0xD686ED63, 0xA8FA8435,
  0x8019AE02, 0x63D9DC2D, 0x5A14D17F, 0xAE4307C2, 0xC248A5B2,
  0x2DD77CB, 0x6F9BF43A, 0x9C452820, 0xF53EBCC, 0x88EC353F,
  0xC50559B2, 0xD14E1ACB, 0xF8FD8ABD, 0x6039BA04, 0x9ED091E5,
  0x803451AC, 0xD62531D7, 0x26215C65, 0xC54DC989, 0xCFE373F8,
  0x34FD6323, 0x8DC0A383, 0xD0EFE372, 0x3B26BC91, 0xAC68E705,
  0x5725470A, 0xCECCBA9D, 0xB661DB6D, 0xFA84D0BB, 0xCF6C264A,
  0xE69F1606, 0x4D2927B5, 0xF7216A15, 0x5C9F009C, 0xEE4D9F97,
  0xE97DF16D, 0x1ED0CEBD, 0x97823E42, 0xCCA3285, 0xA053A50E,
  0xE20972B0, 0x87D50F41, 0x2ED33F0F, 0x83D09E48, 0x5FF59419
};

const unsigned long zoomInCodes[] = {
  0x97DEB5BE, 0xCCF50B7C, 0x8BDB3D6, 0x73FA09CA,
  0x25215AD3, 0x25E13EBD, 0x2E8930AD, 0xD55E3CEE,
  0xBCEB632B, 0xDC1CC68F, 0x69C2CB2E, 0x297B60E2,
  0x846D6D25, 0xCB1E4FBF, 0x9A6AEEC6, 0x80FB2D9A,
  0xD4664936, 0x6585A4C8, 0x9B549FBE, 0xFCF6F003,
  0x7316728B, 0xE99BB106, 0x98A528EC, 0x4C13040A,
  0x147C4C6D, 0x79283472, 0x4EEE824, 0xFDA7FA4F,
  0xCEFA81F7, 0xE0754ABC, 0x822FE22C, 0xCA8C172,
  0xD9053000, 0x44F97D98, 0xBA54FFCC, 0xC1A6962B,
  0x41BBC1A0, 0x14B84C1A, 0x828D461E, 0x87DC20F0,
  0xA1430E8B, 0xDC870190, 0xF07DCD9E, 0x16D47C96,
  0x806C2B91, 0xB61FF409, 0xD78D272A, 0x5200654E,
  0xCAC3CF43, 0x7265CE51, 0x9CC8C32D, 0xCE698D80,
  0x510063BB, 0xF7603BA6, 0xC281D920, 0xB0244CDC,
  0x4E891D03, 0x100CD659, 0x161F5D67, 0xDA7254AD,
  0x543D5C74, 0x191D67B5, 0xFA72B866, 0x403A800C,
  0x1F98B367, 0xD1B7C047, 0x7D51531, 0x47581950,
  0xD2694188, 0x1FEFBE78, 0xCF0A52F9, 0x5B33DFBC,
  0x14D51D16, 0x4FBE90B0, 0xF3523584, 0x4C1F4F64,
  0x36AB4225, 0x88293D87, 0x2993E5D7, 0xB0A34C9C,
  0x48EED928, 0x259205A, 0x8D5E2428, 0xCC14FFC3,
  0xAB01722D
};


const int numIgnoredCodes = sizeof(ignoredCodes) / sizeof(ignoredCodes[0]);
const int numZoomInCodes = sizeof(zoomInCodes) / sizeof(zoomInCodes[0]);

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Iniciar el receptor IR
}

bool isIgnored(unsigned long code) {
  for (int i = 0; i < numIgnoredCodes; i++) {
    if (code == ignoredCodes[i]) {
      return true;
    }
  }
  return false;
}

bool isZoomIn(unsigned long code) {
  for (int i = 0; i < numZoomInCodes; i++) {
    if (code == zoomInCodes[i]) {
      return true;
    }
  }
  return false;
}

void loop() {
  if (irrecv.decode(&results)) {
   
   if (isIgnored(results.value)) {
      irrecv.resume(); // Reanudar el receptor y continuar con el siguiente código
      return; // Salir de la función loop para ignorar este código
    }
     // Mostrar el código recibido en hexadecimal
    if(results.value != 0xFB55006D){
      Serial.print("Código IR recibido: ");
      Serial.println(results.value, HEX);

      // Verificar el código y enviar un mensaje específico
      // Códigos para hacer zoom in
     if (isZoomIn(results.value)) {
    Serial.println("ZOOM_IN"); // Mensaje específico para hacer zoom in
}

      // Códigos para hacer zoom out
      else if (results.value == 0x64BBC0B4) { // Reemplaza con el código IR para zoom out
        Serial.println("ZOOM_OUT"); // Mensaje específico para hacer zoom out
      }
      // Códigos para girar a la derecha
      else if (results.value == 0x42461576) {
        Serial.println("GIRO_DERECHA"); // Mensaje específico para girar a la derecha
      }
    }
    irrecv.resume(); // Reanudar el receptor para recibir el siguiente código
  }
}
