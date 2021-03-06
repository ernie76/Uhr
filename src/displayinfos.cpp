#include <Arduino.h>
#include <U8g2lib.h>
#include <Time.h>

#include "config.h"

#include "schnapszahlen.h"
#include "datecalculations.h"

#include "displayinfos.h"
#include "dateinfo.h"

#include "Images/header.xbm"
#include "Images/header_ccw.xbm"
#include "Images/GPS.xbm"
#include "Images/WLAN.xbm"

// U8G2_IL3820_V2_296X128_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ D5, /* data=*/ D7, /* cs=*/ D8, /* dc=*/ D2, /* reset=*/ D3);
U8G2_IL3820_V2_296X128_F_4W_SW_SPI u8g2(U8G2_R0, DISPLAY_PIN_CLOCK, DISPLAY_PIN_DATA, DISPLAY_PIN_CS, DISPLAY_PIN_DC, DISPLAY_PIN_RESET);

extern struct datum hochzeitstag;
extern unsigned int next_update;


void mehrzahl(char* result, int zahl, const char *einzahl, const char *mehrzahl) {
  switch (zahl) {
    case 0:
      strcpy(result, "");
      break;

    case 1:
      sprintf(result, "%i %s", zahl, einzahl);
      break;

    default:
      sprintf(result, "%i %s", zahl, mehrzahl);
      break;
  }
}

int getHochzeitstagTitel(int index, char *titel) {
    for (int i=0; i < hochzeitstage_count; i++) {
      struct hochzeitstag ht = hochzeitstage[i];
      if (ht.period == index) {
        strcpy(titel, ht.name);
        return true;
      }
    }
    return false;
}

void clearDisplay() {
  u8g2.firstPage();
  u8g2.setPowerSave(0);	// before drawing, enable charge pump (req. 300ms)
  do {
    u8g2.clearDisplay();
  } while ( u8g2.nextPage() );
  u8g2.setPowerSave(1);	// disable charge pump
}

u8g2_uint_t get_x_for_centered_text(char *text, const uint8_t *font) {
  u8g2_uint_t text_width, display_width;
  u8g2.setFont(font);
  text_width = u8g2.getStrWidth(text);
  display_width = u8g2.getDisplayWidth();
  // Serial.print("Display width: "); Serial.println(display_width);
  return (display_width / 2) - (text_width / 2);
}

void drawStrCentered(char *text, int y, const uint8_t *font) {
  u8g2.setFont(font);
  u8g2.drawStr(get_x_for_centered_text(text, font), y, text);
}

void drawHeaderLarge() {
  // graphic commands to redraw the complete screen should be placed here
  u8g2.drawXBMP(23, 0, header_width, header_height, header_bits);
}

void drawHeaderccw() {
  u8g2.drawXBMP(0, 0, header_ccw_width, header_ccw_height, header_ccw_bits);
}

void drawObtainingTime() {
  char text[] = "Empfange Zeit...";
  const uint8_t *font = u8g2_font_helvR12_tf;
  // graphic commands to redraw the complete screen should be placed here
  u8g2.drawXBMP(14, 14, GPS_width, GPS_height, GPS_bits);
  u8g2.setFont(font);

  u8g2.drawStr(140, 54, text);

  sprintf(text, "%02i:%02i:%02i", hour(), minute(), second());
  u8g2.drawStr(140, 84, text);
}

void drawIPAddress(char *ip, char *wifissid) {
  char text[] = "IP Address: ";
  const uint8_t *font = u8g2_font_helvR10_tf;
  // graphic commands to redraw the complete screen should be placed here
  u8g2.drawXBMP(14, 14, WLAN_width, WLAN_height, WLAN_bits);
  u8g2.setFont(font);
  u8g2.drawStr(140, 25, text);
  u8g2.drawStr(140, 50, ip);
  sprintf(text,"WLAN-SSID:");
  u8g2.drawStr(140, 85, text);
  u8g2.drawStr(140, 110, wifissid);
}

void drawAbout() {
  char text[] = "Coded by";
  const uint8_t *font = u8g2_font_helvR12_tf;
  // graphic commands to redraw the complete screen should be placed here
  u8g2.drawXBMP(14, 14, WLAN_width, WLAN_height, WLAN_bits);
  u8g2.setFont(font);
  u8g2.drawStr(get_x_for_centered_text(text,font)+50, 54, text);
  sprintf(text,"Thomas Keil");
  u8g2.drawStr(get_x_for_centered_text(text,font)+50, 75, text);
}

void drawCaptivePortal(char *apname, char *ip) {
  char text[90];
  const uint8_t *font = u8g2_font_helvR10_tf;
  // graphic commands to redraw the complete screen should be placed here
  u8g2.drawXBMP(14, 14, WLAN_width, WLAN_height, WLAN_bits);
  u8g2.setFont(font);
  int zeile = 35;
  sprintf(text,"Bitte mit dem WLAN");
  u8g2.drawStr(get_x_for_centered_text(text,font)+50, zeile, text);
  sprintf(text,"\"%s\"",apname);
  u8g2.drawStr(get_x_for_centered_text(text,font)+50, zeile+15, text);
  sprintf(text,"verbinden.");
  u8g2.drawStr(get_x_for_centered_text(text,font)+50, zeile+30, text);
  sprintf(text,"Und im Browser");
  u8g2.drawStr(get_x_for_centered_text(text,font)+50, zeile+45, text);
  sprintf(text,"http://%s",ip);
  u8g2.drawStr(get_x_for_centered_text(text,font)+50, zeile+60, text);
  sprintf(text,"aufrufen.");
  u8g2.drawStr(get_x_for_centered_text(text,font)+50, zeile+75, text);
}

void drawVerheiratetSeit(struct periode result) {
  char header[] = "Verheiratet seit";
  const uint8_t *font = u8g2_font_helvR12_tf;


  drawStrCentered(header, 54, font);

  printf("%i Jahre, %i Monate, %i Tage, %i Monate gesamt, %i Tage gesamt, %i Stunden\n", result.jahre, result.monate, result.tage, result.monate_gesamt, result.tage_gesamt, result.stunden);
  char text[40] = "";
  char jahre_text[6]; // "Jahre" + \0
  char monate_text[7];
  char tage_text[5];
  char stunden_text[8];

  if (result.jahre > 0) {
    mehrzahl(jahre_text, result.jahre, clckst[CLOCK_STRING_YEAR_SINGLULAR], clckst[CLOCK_STRING_YEAR_PLURAL]);
    strcat(text, jahre_text);

    if (result.monate > 0) {
      strcat(text, ", ");
      mehrzahl(monate_text, result.monate, clckst[CLOCK_STRING_MONTH_SINGLULAR], clckst[CLOCK_STRING_MONTH_PLURAL]);
      strcat(text, monate_text);
    }

    if (result.tage > 0) {
      strcat(text, ", ");
      mehrzahl(tage_text, result.tage, clckst[CLOCK_STRING_DAY_SINGLULAR], clckst[CLOCK_STRING_DAY_PLURAL]);
      strcat(text, tage_text);
    }
  } else if (result.monate > 0) {
    mehrzahl(monate_text, result.monate, clckst[CLOCK_STRING_MONTH_SINGLULAR], clckst[CLOCK_STRING_MONTH_PLURAL]);
    strcat(text,monate_text);

    if (result.tage > 0) {
      strcat(text, ", ");
      mehrzahl(tage_text, result.tage, clckst[CLOCK_STRING_DAY_SINGLULAR], clckst[CLOCK_STRING_DAY_PLURAL]);
      strcat(text, tage_text);
    }

    if (result.stunden > 0) {
      strcat(text, ", ");
      mehrzahl(stunden_text, result.stunden, clckst[CLOCK_STRING_HOUR_SINGULAR], clckst[CLOCK_STRING_HOUR_PLURAL]);
      strcat(text, stunden_text);
    }

  } else if (result.tage > 0) {
    mehrzahl(tage_text, result.tage, clckst[CLOCK_STRING_DAY_SINGLULAR], clckst[CLOCK_STRING_DAY_PLURAL]);
    strcat(text, tage_text);

    if (result.stunden > 0) {
      strcat(text, ", ");
      mehrzahl(stunden_text, result.stunden, clckst[CLOCK_STRING_HOUR_SINGULAR], clckst[CLOCK_STRING_HOUR_PLURAL]);
      strcat(text, stunden_text);
    }

  } else {
    mehrzahl(stunden_text, result.stunden, clckst[CLOCK_STRING_HOUR_SINGULAR], clckst[CLOCK_STRING_HOUR_PLURAL]);
    strcat(text, stunden_text);
  }

  drawStrCentered(text, 80, font);
  Serial.printf("Ausgabe : %s\n", text);
  Serial.printf("Zusatz: Stunden gesamt: %i, Tage gesamt: %i, Monate gesamt: %i\n", result.stunden_gesamt, result.tage_gesamt, result.monate_gesamt);

}

void drawSchnapszahl(struct periode result) {

}

void drawAdditionalInfo(struct periode result) {
  const uint8_t *font2 = u8g2_font_helvR08_tf;

  #ifdef DRAW_ADDITIONAL_ELAPSED
  char zusatztext[80] = "";
  sprintf(zusatztext,"Stunden: %i, Tage: %i, Monate: %i\n", result.stunden_gesamt, result.tage_gesamt, result.monate_gesamt);
  drawStrCentered(zusatztext, 100, font2);
  #endif

  #ifdef DRAW_CURRENT_TIME
  char uhrzeit[40] = "";
  sprintf(uhrzeit, "%02i.%02i.%04i %02i:%02i:%02i", day(), month(), year(), hour(), minute(), second());
  drawStrCentered(uhrzeit, 120, font2);
  #endif


}

void drawHochzeitstagInfo(int tag_index) {
  int day_to_display = 0; // "escape"-day to display if we don't have any information.
  for (int zaehler = 1; zaehler < hochzeitstage_count; zaehler++) {
    if (tag_index == hochzeitstage[zaehler].period) {
      day_to_display = zaehler;
      break;
    }
  }

  const uint8_t *large_font = u8g2_font_9x18B_tf;
  u8g2.setFont(large_font);
  char ueberschrift[50];
  if (day_to_display) {
    sprintf(ueberschrift,"%i. %s",hochzeitstage[day_to_display].period, hochzeitstage[day_to_display].name);
  } else {
    sprintf(ueberschrift,"%i. %s",tag_index, hochzeitstage[day_to_display].name);
  }
  u8g2.drawStr(55, 10, ueberschrift);


  const uint8_t *font = u8g2_font_lucasfont_alternate_tf;
  u8g2.setFont(font);

  char delimiter[] = " ";
  char *ptr;

  char text[800];
  strcpy(text, hochzeitstage[day_to_display].text);

  // initialisieren und ersten Abschnitt erstellen, den werfen wir gleich weg
  ptr = strtok(text, delimiter);

  int x = 55; int y = 25; // The width of the ccw-image and beneath the headline
  int width = 0;

  while(ptr != NULL) {
    // Serial.print(ptr); Serial.print(" ");
    width = u8g2.getStrWidth(ptr); // Get width of word
    if (width > u8g2.getDisplayWidth() - x) { // is it too long for the line?
      x = 55; // cursor to the left, next to the counter-clock-wise image
      y += 10; // next line
    }
    u8g2.drawStr(x, y, ptr);
    x += width + 4; // advance the cursor by one "whitespace"

    ptr = strtok(NULL, delimiter); // get the next token.

  }


}

void drawNextWeddingDay(struct datum date, int count) {
  const uint8_t *font = u8g2_font_helvR12_tf;
  u8g2.setFont(font);

  char text[40] = "";
  sprintf(text, "Am %02i.%02i.%i ist der %i. Hochzeitstag", date.tag, date.monat, date.jahr, count);
  u8g2.drawStr(get_x_for_centered_text(text, font), 108, text);

  char titel[25] = "";
  if (getHochzeitstagTitel(count, titel)) {
    u8g2.drawStr(get_x_for_centered_text(titel, font), 125, titel);
  }
}

void screenIPAddress(char *ip, char *wifissid) {
  u8g2.firstPage();
  u8g2.setPowerSave(0); // before drawing, enable charge pump (req. 300ms)
  do {
    drawIPAddress(ip, wifissid);
  } while ( u8g2.nextPage() );
  u8g2.setPowerSave(1); // disable charge pump

  delay(1300);

  next_update = 0;
}

void screenAbout() {
  u8g2.firstPage();
  u8g2.setPowerSave(0); // before drawing, enable charge pump (req. 300ms)
  do {
    drawAbout();
  } while ( u8g2.nextPage() );
  u8g2.setPowerSave(1); // disable charge pump

  delay(1300);

  next_update = 0;
}

void screenCaptivePortal(char *apname, char *ip) {
  Serial.print("apname = ");
  Serial.println(apname);
  Serial.print("ip = ");
  Serial.println(ip);
  u8g2.firstPage();
  u8g2.setPowerSave(0); // before drawing, enable charge pump (req. 300ms)
  do {
    drawCaptivePortal(apname,ip);
  } while ( u8g2.nextPage() );
  u8g2.setPowerSave(1); // disable charge pump
}

void screenVerheiratetSeit(struct periode elapsed) {
  u8g2.firstPage();
  u8g2.setPowerSave(0);	// before drawing, enable charge pump (req. 300ms)
  do {
    drawHeaderLarge();
    drawVerheiratetSeit(elapsed);
    drawAdditionalInfo(elapsed);
  } while ( u8g2.nextPage() );
  u8g2.setPowerSave(1);	// disable charge pump
}

void screenHochzeitstaginfo(int tag_index) {
  u8g2.firstPage();
  u8g2.setPowerSave(0);	// before drawing, enable charge pump (req. 300ms)
  do {
    drawHeaderccw();
    drawHochzeitstagInfo(tag_index);
  } while ( u8g2.nextPage() );
  u8g2.setPowerSave(1);	// disable charge pump

}
void screenUpcomingWeddingDay(struct periode elapsed, struct datum next_wedding_day, int count) {
  u8g2.firstPage();
  u8g2.setPowerSave(0);	// before drawing, enable charge pump (req. 300ms)
  do {
    drawHeaderLarge();
    drawVerheiratetSeit(elapsed);
    drawNextWeddingDay(next_wedding_day, count);
  } while ( u8g2.nextPage() );
  u8g2.setPowerSave(1);	// disable charge pump

}

void screenSchnapszahl(struct periode elapsed, char *text, char *description) {
  const uint8_t *font = u8g2_font_helvR12_tf;
  const uint8_t *font2 = u8g2_font_helvR08_tf;

  u8g2.firstPage();
  u8g2.setPowerSave(0);	// before drawing, enable charge pump (req. 300ms)
  do {

    drawHeaderLarge();
    drawVerheiratetSeit(elapsed);

    drawStrCentered(text, 105, font);
    drawStrCentered(description, 125, font2);

  } while ( u8g2.nextPage() );
  u8g2.setPowerSave(1);	// disable charge pump
}
