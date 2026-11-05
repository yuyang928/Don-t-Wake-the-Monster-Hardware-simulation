#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void OLED_init();
void OLED_change_M_status(char status);
void OLED_display_time(unsigned long time);

class coord{   
  public:
    int x;
    int y;
    coord(int x, int y) {
      this->x = x;
      this->y = y;
    }
    int getX() {
      return x;
    }
    int getY() {
      return y;
    }
}

coord find_coord(int len, int y_offset=0, int x_offset=0) {
    int x = (SCREEN_WIDTH - len) / 2 + x_offset;
    int y = (SCREEN_HEIGHT - 8) / 2 + y_offset;
    return coord(x, y);
}

void OLED_init(){
    Wire.begin(21, 22); // Initialize I2C with SDA on GPIO 21 and SCL on GPIO 22
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
}

void OLED_change_M_status(char status) {
    coord prob_coord = find_coord(strlen(status));
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(prob_coord.getX(), prob_coord.getY());
    display.println(status);
    display.display();
}
void OLED_display_time(unsigned long time) {
    unsigned long sec= time /1000;
    int min = sec / 60;
    sec = sec % 60;
    char buffer[20];
    sprintf(buffer, "Time: %d:%02d", min, sec);
    coord prob_coord = find_coord(strlen(buffer));
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(prob_coord.getX(), prob_coord.getY());
    display.println(buffer);
    display.display();
}