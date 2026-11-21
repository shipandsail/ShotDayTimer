// ShotDayTimer: weekly shot-day countdown and injection-site rotation for DIY reminder devices.
// Logging and reminders only: it never recommends or calculates doses.
// https://bluedoseapp.com/features/glp-1-shot-reminder/
#ifndef SHOT_DAY_TIMER_H
#define SHOT_DAY_TIMER_H
#include <stdint.h>

class ShotDayTimer {
 public:
  enum Site : uint8_t { ABDOMEN_LEFT, ABDOMEN_RIGHT, THIGH_LEFT, THIGH_RIGHT, ARM_LEFT, ARM_RIGHT, SITE_COUNT };
  // shotWeekday: 0 = Sunday ... 6 = Saturday
  explicit ShotDayTimer(uint8_t shotWeekday) : shotDay_(shotWeekday % 7), counter_(0) {
    for (uint8_t i = 0; i < SITE_COUNT; i++) lastUse_[i] = 0;
  }
  // Days until the next shot day (0 = today), given today's weekday 0..6.
  uint8_t daysUntil(uint8_t todayWeekday) const { return (uint8_t)((shotDay_ + 7 - (todayWeekday % 7)) % 7); }
  bool isShotDay(uint8_t todayWeekday) const { return daysUntil(todayWeekday) == 0; }
  // Record that a site was used.
  void logSite(Site s) { if (s < SITE_COUNT) lastUse_[s] = ++counter_; }
  // Least recently used site (never-used first, in order).
  Site nextSite() const {
    uint8_t best = 0;
    for (uint8_t i = 1; i < SITE_COUNT; i++) if (lastUse_[i] < lastUse_[best]) best = i;
    return (Site)best;
  }
  static const char* siteName(Site s) {
    static const char* names[] = {"Abdomen, left", "Abdomen, right", "Thigh, left", "Thigh, right", "Upper arm, left", "Upper arm, right"};
    return s < SITE_COUNT ? names[s] : "?";
  }
 private:
  uint8_t shotDay_;
  uint32_t counter_;
  uint32_t lastUse_[SITE_COUNT];
};
#endif
