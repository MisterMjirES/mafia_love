const uint8_t ch[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 16, 16, 16, 16, 17, 18, 18, 18, 17, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 18, 21, 22, 16, 16, 17, 16, 15, 15, 16, 16, 16, 16, 16, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 22, 23, 16, 16, 23, 22, 16, 16, 16, 16, 16, 15, 16, 16, 16, 16, 16, 16, 15, 15, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 23, 24, 23, 16, 16, 16, 17, 16, 16, 16, 16, 16, 15, 16, 16, 16, 16, 16, 16, 15, 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 24, 23, 23, 16, 16, 17, 18, 19, 19, 17, 16, 16, 15, 15, 16, 16, 16, 16, 16, 15, 15, 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 16, 23, 22, 21, 19, 19, 19, 19, 19, 19, 18, 17, 16, 16, 15, 16, 16, 16, 16, 16, 16, 15, 15, 15, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 17, 16, 16, 16, 15, 16, 16, 16, 16, 16, 16, 15, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 20, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 17, 17, 16, 16, 15, 15, 16, 16, 16, 16, 16, 15, 15, 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 23, 20, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 19, 17, 16, 16, 15, 16, 16, 16, 16, 16, 16, 15, 15, 15, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 23, 20, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 39, 18, 17, 16, 16, 15, 16, 16, 16, 16, 16, 16, 15, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 20, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 17, 21, 21, 20, 16, 16, 15, 16, 16, 16, 16, 16, 16, 15, 15, 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 23, 22, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 17, 17, 21, 22, 22, 23, 16, 15, 16, 16, 16, 16, 16, 16, 16, 15, 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 22, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 17, 17, 21, 22, 22, 23, 16, 15, 16, 16, 16, 16, 16, 16, 16, 15, 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 22, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 17, 18, 22, 22, 22, 24, 16, 15, 16, 16, 16, 16, 16, 16, 16, 15, 15, 16, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 23, 23, 22, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 17, 18, 22, 22, 23, 24, 16, 15, 16, 16, 16, 16, 16, 16, 16, 15, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 23, 23, 22, 19, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 18, 18, 22, 22, 23, 24, 16, 15, 16, 16, 16, 16, 16, 16, 16, 15, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 23, 23, 23, 21, 19, 19, 19, 19, 19, 19, 19, 19, 19, 20, 18, 18, 21, 22, 22, 24, 24, 16, 15, 16, 16, 16, 16, 16, 16, 16, 15, 15, 16, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 23, 23, 23, 21, 19, 19, 19, 19, 19, 19, 19, 19, 20, 21, 18, 18, 21, 22, 22, 24, 23, 16, 15, 16, 16, 16, 16, 16, 16, 16, 15, 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 23, 23, 20, 19, 19, 19, 19, 19, 19, 19, 20, 20, 21, 18, 18, 21, 22, 22, 24, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 15, 16, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 23, 22, 22, 20, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 18, 18, 20, 21, 23, 24, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 23, 22, 21, 20, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 18, 18, 20, 20, 22, 23, 15, 16, 16, 16, 16, 16, 16, 16, 16, 15, 16, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 16, 22, 21, 19, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 18, 18, 20, 20, 22, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 18, 16, 16, 23, 16, 22, 22, 21, 21, 20, 19, 19, 19, 19, 19, 19, 19, 20, 18, 18, 19, 18, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 15, 16, 16, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 16, 16, 17, 24, 16, 16, 23, 16, 17, 22, 22, 22, 22, 22, 21, 20, 19, 19, 19, 19, 19, 17, 18, 19, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 15, 16, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 17, 16, 16, 15, 15, 16, 24, 24, 16, 16, 16, 16, 16, 16, 16, 17, 22, 23, 23, 23, 22, 22, 21, 20, 18, 17, 17, 17, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 16, 16, 15, 15, 15, 15, 16, 24, 24, 15, 16, 16, 16, 16, 16, 16, 22, 22, 22, 22, 22, 22, 22, 23, 23, 17, 17, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 16, 16, 16, 15, 15, 15, 16, 23, 24, 24, 16, 16, 16, 16, 16, 16, 16, 22, 23, 14, 14, 23, 14, 23, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 15, 15, 15, 15, 16, 23, 24, 24, 16, 16, 16, 16, 16, 16, 16, 14, 14, 23, 23, 14, 14, 14, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 15, 15, 15, 15, 15, 16, 23, 24, 24, 16, 23, 16, 16, 17, 16, 16, 14, 14, 14, 23, 23, 14, 23, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 16, 15, 15, 15, 15, 15, 16, 23, 24, 24, 16, 16, 16, 16, 16, 16, 16, 14, 14, 23, 14, 14, 14, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 16, 15, 15, 15, 15, 15, 16, 23, 23, 24, 16, 14, 16, 16, 16, 16, 16, 14, 14, 14, 23, 23, 23, 23, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 16, 16, 15, 15, 15, 15, 15, 15, 16, 18, 19, 20, 16, 14, 16, 16, 23, 16, 16, 22, 22, 22, 22, 22, 22, 17, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 16, 17, 17, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 15, 15, 15, 15, 15, 15, 16, 18, 10, 12, 16, 15, 16, 16, 17, 16, 16, 17, 17, 17, 17, 17, 17, 16, 17, 17, 17, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 16, 15, 15, 15, 15, 15, 15, 16, 22, 23, 24, 16, 14, 15, 15, 16, 16, 17, 22, 22, 21, 22, 22, 17, 17, 17, 18, 17, 17, 17, 17, 18, 17, 17, 17, 17, 17, 17, 17, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 16, 16, 15, 15, 15, 15, 15, 15, 16, 23, 24, 24, 24, 23, 23, 14, 23, 17, 17, 17, 17, 17, 17, 17, 17, 22, 22, 22, 18, 17, 17, 22, 21, 18, 17, 17, 18, 18, 22, 22, 17, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 15, 15, 15, 15, 15, 16, 16, 24, 24, 24, 24, 23, 24, 14, 23, 23, 23, 22, 22, 22, 22, 22, 22, 22, 22, 18, 18, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 15, 15, 15, 15, 15, 16, 17, 22, 21, 22, 16, 16, 24, 16, 23, 17, 22, 38, 22, 22, 17, 18, 19, 19, 19, 19, 39, 21, 21, 20, 20, 18, 17, 20, 19, 20, 20, 19, 20, 17, 17, 20, 20, 0, 21, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 15, 15, 15, 15, 15, 16, 20, 19, 19, 12, 16, 16, 17, 16, 17, 17, 22, 17, 18, 19, 29, 29, 29, 39, 39, 21, 39, 19, 19, 19, 19, 20, 20, 20, 19, 19, 19, 19, 19, 20, 20, 16, 17, 17, 17, 20, 39, 22, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 16, 15, 15, 15, 15, 15, 17, 23, 21, 12, 14, 16, 16, 16, 16, 16, 22, 17, 19, 19, 19, 19, 19, 39, 21, 39, 19, 19, 20, 19, 20, 19, 19, 17, 20, 20, 17, 17, 19, 19, 17, 16, 16, 19, 17, 16, 17, 18, 39, 22, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 16, 15, 15, 16, 16, 16, 23, 24, 24, 24, 16, 16, 16, 16, 16, 17, 22, 17, 19, 19, 19, 19, 39, 39, 21, 39, 19, 20, 20, 19, 19, 19, 20, 17, 17, 20, 20, 16, 16, 17, 17, 17, 16, 16, 16, 16, 16, 17, 19, 39, 22, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 16, 15, 16, 16, 16, 16, 24, 24, 24, 24, 16, 16, 16, 16, 16, 17, 22, 22, 18, 19, 19, 19, 29, 39, 21, 39, 19, 19, 20, 20, 20, 20, 20, 17, 20, 20, 20, 16, 16, 17, 17, 17, 16, 16, 16, 16, 16, 17, 29, 39, 22, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 16, 15, 16, 16, 16, 17, 24, 24, 24, 24, 16, 16, 16, 16, 17, 17, 22, 22, 17, 17, 19, 19, 19, 29, 21, 22, 18, 19, 19, 20, 20, 20, 20, 17, 17, 12, 12, 17, 17, 17, 12, 12, 12, 16, 16, 16, 20, 19, 29, 39, 21, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 16, 16, 16, 16, 16, 23, 24, 24, 24, 16, 16, 16, 16, 22, 17, 21, 21, 22, 22, 22, 17, 18, 18, 18, 18, 21, 22, 20, 19, 19, 19, 20, 20, 17, 17, 17, 17, 17, 17, 17, 17, 17, 20, 18, 19, 39, 39, 21, 39, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 17, 17, 16, 16, 16, 17, 22, 22, 17, 16, 16, 16, 17, 17, 17, 21, 22, 22, 38, 21, 17, 17, 17, 22, 18, 21, 21, 18, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 19, 39, 39, 21, 21, 39, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 18, 18, 22, 22, 22, 23, 23, 17, 16, 16, 16, 16, 16, 16, 17, 21, 22, 18, 17, 17, 16, 16, 17, 22, 22, 22, 22, 21, 39, 39, 20, 20, 19, 19, 19, 19, 19, 19, 19, 20, 21, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 16, 17, 18, 21, 38, 38, 38, 27, 27, 22, 22, 22, 22, 22, 17, 22, 22, 11, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 21, 18, 18, 17, 18, 18, 21, 21, 18, 18, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 17, 18, 18, 21, 38, 38, 38, 22, 22, 22, 22, 22, 22, 22, 22, 22, 21, 21, 22, 22, 27, 22, 22, 22, 22, 22, 22, 38, 38, 21, 17, 20, 20, 18, 21, 18, 18, 18, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 17, 39, 39, 17, 22, 22, 27, 27, 22, 22, 22, 22, 22, 22, 23, 22, 23, 23, 23, 23, 23, 23, 22, 22, 22, 22, 22, 22, 22, 22, 22, 21, 21, 20, 17, 17, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 22, 18, 18, 18, 18, 39, 27, 27, 38, 38, 38, 38, 22, 22, 14, 22, 24, 22, 22, 23, 23, 23, 24, 23, 23, 22, 22, 22, 22, 22, 21, 39, 22, 20, 20, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 17, 16, 16, 17, 18, 38, 38, 38, 38, 22, 22, 17, 17, 23, 23, 23, 23, 23, 23, 23, 22, 23, 24, 24, 22, 22, 22, 22, 22, 21, 20, 17, 17, 17, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 17, 17, 17, 17, 17, 17, 18, 18, 22, 23, 14, 23, 23, 23, 23, 23, 23, 23, 23, 22, 22, 22, 22, 21, 21, 21, 21, 20, 20, 17, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 22, 23, 16, 16, 16, 17, 14, 22, 22, 24, 22, 22, 23, 22, 22, 23, 23, 22, 22, 22, 17, 17, 20, 39, 21, 20, 17, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 17, 16, 16, 23, 22, 22, 22, 23, 23, 17, 14, 22, 22, 23, 23, 22, 22, 21, 21, 21, 20, 20, 17, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 16, 16, 22, 38, 38, 22, 22, 22, 22, 17, 22, 22, 22, 22, 22, 21, 21, 21, 18, 18, 18, 18, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 22, 27, 38, 22, 22, 22, 22, 22, 22, 22, 22, 22, 27, 22, 17, 18, 20, 18, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 23, 27, 27, 22, 22, 18, 18, 19, 18, 39, 19, 19, 18, 19, 19, 20, 20, 20, 20, 21, 17, 17, 17, 20, 20, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 17, 22, 38, 27, 27, 18, 18, 19, 19, 39, 39, 19, 19, 19, 20, 20, 17, 17, 17, 17, 16, 16, 16, 16, 17, 20, 21, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 24, 24, 24, 23, 22, 18, 18, 18, 18, 18, 18, 18, 18, 18, 20, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 22, 22, 22, 22, 24, 24, 23, 23, 17, 17, 18, 17, 17, 17, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 22, 23, 23, 23, 22, 17, 22, 17, 18, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 

};