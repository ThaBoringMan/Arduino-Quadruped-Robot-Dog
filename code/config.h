constexpr uint16_t SERVO_FREQ = 50;      // Hz
constexpr uint16_t MIN_PULSE_US = 500;   // 0°
constexpr uint16_t MAX_PULSE_US = 2500;  // 180°
constexpr uint8_t MIN_ANGLE = 0;
constexpr uint8_t MAX_ANGLE = 180;

/* ------------ tolerance table (index = PCA9685 channel) ------------- */
float tolerance[16] = {                                                                                                   
  0.96, /* 0  BR_W */
  0.94, /* 1  BR_A */
  1.05, /* 2  BR_J */
  1.00, /* 3  (unused) */
  1.05, /* 4  BL_W */
  1.01, /* 5  BL_A */
  1.05, /* 6  BL_J */
  1.00, /* 7  (unused) */
  1.00, /* 8  FR_W */
  0.97, /* 9  FR_A */
  1.12, /* 10 FR_J */
  1.00, /* 11 (unused) */
  0.8, /* 12 FL_W */
  1.0, /* 13 FL_A */
  0.77, /* 14 FL_J */
  1.00  /* 15 (unused) */
};

/* ------------ name → channel lookup --------------------------------- */
int channelFromName(const String &n) {
  if (n == "BR_W") return 0;
  if (n == "BR_A") return 1;
  if (n == "BR_J") return 2;
  if (n == "BL_W") return 4;
  if (n == "BL_A") return 5;
  if (n == "BL_J") return 6;
  if (n == "FR_W") return 8;
  if (n == "FR_A") return 9;
  if (n == "FR_J") return 10;
  if (n == "FL_W") return 12;
  if (n == "FL_A") return 13;
  if (n == "FL_J") return 14;
  return -1;
}
