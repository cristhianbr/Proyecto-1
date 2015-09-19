void B(uint32_t *reg, int salto);

void BEQ(uint32_t *reg, int salto, char *flags);

void BNE(uint32_t *reg, int salto, char *flags);

void BCS(uint32_t *reg, int salto, char *flags);

void BCC(uint32_t *reg, int salto, char *flags);

void BMI(uint32_t *reg, int salto, char *flags);

void BPL(uint32_t *reg, int salto, char *flags);

void BVS(uint32_t *reg, int salto, char *flags);

void BVC(uint32_t *reg, int salto, char *flags);

void BHI(uint32_t *reg, int salto, char *flags);

void BLS(uint32_t *reg, int salto, char *flags);

void BGE(uint32_t *reg, int salto, char *flags);

void BLT(uint32_t *reg, int salto, char *flags);

void BGT(uint32_t *reg, int salto, char *flags);

void BLE(uint32_t *reg, int salto, char *flags);

void BLA(uint32_t *reg, int salto);

void BL(uint32_t *reg, uint32_t *reg2, int salto);

void BX(uint32_t *reg, uint32_t Rm);

void BLX(uint32_t *reg, uint32_t *reg2, uint32_t Rm);
