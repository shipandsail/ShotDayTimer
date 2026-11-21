# ShotDayTimer

Header-only weekly shot-day countdown and injection-site rotation for DIY medication reminder devices (pair it with an RTC and a display or buzzer).

- `daysUntil(todayWeekday)` / `isShotDay()`
- `logSite()` and `nextSite()`: least-recently-used rotation across six injection sites
- `siteName()`

See `examples/Basic`. Logging and reminders only: it never recommends or calculates doses. Follow your medicine's instructions and your healthcare provider.

More: https://bluedoseapp.com/features/glp-1-shot-reminder/

MIT License.
