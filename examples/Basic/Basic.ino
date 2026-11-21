#include <ShotDayTimer.h>

ShotDayTimer timer(3);  // weekly shot on Wednesday

void setup() {
  Serial.begin(9600);
  uint8_t today = 6;  // Saturday (read this from your RTC)
  Serial.print("Days until shot day: "); Serial.println(timer.daysUntil(today));
  timer.logSite(ShotDayTimer::ABDOMEN_LEFT);
  timer.logSite(ShotDayTimer::THIGH_RIGHT);
  Serial.print("Next site: "); Serial.println(ShotDayTimer::siteName(timer.nextSite()));
}

void loop() {}
