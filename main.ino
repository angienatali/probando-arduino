#include <ExploraTFT.h>

// Definir pines para la pantalla TFT
#define TFT_CS   10
#define TFT_RST  9
#define TFT_DC   8

// Crear objeto TFT
ExploraTFT tft = ExploraTFT(TFT_CS, TFT_DC, TFT_RST);

// Definir pines para los botones
const int buttonUpPin = 2;
const int buttonRightPin = 3;
const int buttonDownPin = 4;
const int buttonLeftPin = 5;

// Definir colores
const uint16_t BLUE    = 0x001F; // RGB 0,0,255
const uint16_t RED     = 0xF800; // RGB 255,0,0
const uint16_t GREEN   = 0x07E0; // RGB 0,255,0
const uint16_t YELLOW  = 0xFFE0; // RGB 255,255,0
const uint16_t BLACK   = 0x0000; // RGB 0,0,0

// Variables para almacenar el estado anterior de los botones
int lastButtonUpState = HIGH;
int lastButtonRightState = HIGH;
int lastButtonDownState = HIGH;
int lastButtonLeftState = HIGH;

void setup() {
  // Inicializar la pantalla TFT
  tft.begin();
  tft.setRotation(1); // Ajusta la rotación según tu configuración
  tft.fillScreen(BLACK); // Pantalla negra al inicio

  // Configurar los pines de los botones
  pinMode(buttonUpPin, INPUT_PULLUP);
  pinMode(buttonRightPin, INPUT_PULLUP);
  pinMode(buttonDownPin, INPUT_PULLUP);
  pinMode(buttonLeftPin, INPUT_PULLUP);
}

void loop() {
  // Leer el estado de los botones
  int buttonUpState = digitalRead(buttonUpPin);
  int buttonRightState = digitalRead(buttonRightPin);
  int buttonDownState = digitalRead(buttonDownPin);
  int buttonLeftState = digitalRead(buttonLeftPin);

  // Cambiar el color de la pantalla según el botón presionado
  if (buttonUpState == LOW && lastButtonUpState == HIGH) {
    tft.fillScreen(BLUE);
  }
  if (buttonRightState == LOW && lastButtonRightState == HIGH) {
    tft.fillScreen(RED);
  }
  if (buttonDownState == LOW && lastButtonDownState == HIGH) {
    tft.fillScreen(YELLOW);
  }
  if (buttonLeftState == LOW && lastButtonLeftState == HIGH) {
    tft.fillScreen(GREEN);
  }

  // Actualizar el estado anterior de los botones
  lastButtonUpState = buttonUpState;
  lastButtonRightState = buttonRightState;
  lastButtonDownState = buttonDownState;
  lastButtonLeftState = buttonLeftState;

  delay(50); // Pequeña pausa para evitar rebotes y lecturas erráticas
}
