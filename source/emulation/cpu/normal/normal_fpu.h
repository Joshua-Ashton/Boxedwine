/* WATCHIT : ALWAYS UPDATE REGISTERS BEFORE AND AFTER USING THEM
            STATUS WORD =>	cpu->fpu.SET_TOP(fpu.top) BEFORE a read
            fpu.top=cpu->fpu.GET_TOP() after a write;
            */

void OPCALL normal_FADD_SINGLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FADD_EA();
    NEXT();
}

void OPCALL normal_FMUL_SINGLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FMUL_EA();
    NEXT();
}

void OPCALL normal_FCOM_SINGLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FCOM_EA();
    NEXT();
}

void OPCALL normal_FCOM_SINGLE_REAL_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FCOM_EA();
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FSUB_SINGLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FSUB_EA();
    NEXT();
}

void OPCALL normal_FSUBR_SINGLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FSUBR_EA();
    NEXT();
}

void OPCALL normal_FDIV_SINGLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FDIV_EA();
    NEXT();
}

void OPCALL normal_FDIVR_SINGLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FDIVR_EA();
    NEXT();
}

void OPCALL normal_FADD_ST0_STj(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FADD(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FMUL_ST0_STj(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FMUL(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FCOM_STi(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCOM(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FCOM_STi_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCOM(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FSUB_ST0_STj(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSUB(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FSUBR_ST0_STj(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSUBR(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FDIV_ST0_STj(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FDIV(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FDIVR_ST0_STj(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FDIVR(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FLD_SINGLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    U32 value = readd(eaa(cpu, op)); // might generate PF, so do before we adjust the stack
    cpu->fpu.PREP_PUSH();
    cpu->fpu.FLD_F32(value, cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FST_SINGLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_F32(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FST_SINGLE_REAL_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_F32(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FLDENV(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLDENV(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FLDCW(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLDCW(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FNSTENV(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSTENV(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FNSTCW(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    writew(eaa(cpu, op), cpu->fpu.CW());
    NEXT();
}

void OPCALL normal_FLD_STi(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    int reg_from = cpu->fpu.STV(op->reg);
    cpu->fpu.PREP_PUSH();
    cpu->fpu.FST(reg_from, cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FXCH_STi(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
#ifdef LOG_FPU
    LOG("FXCH_STi %d,%d(%d)", cpu->fpu.STV(0), cpu->fpu.STV(op->reg), op->reg); 
    LOG("    before");
    LOG_STACK();
#endif
    cpu->fpu.FXCH(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FNOP(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    NEXT();
}

void OPCALL normal_FCHS(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCHS();
    NEXT();
}

void OPCALL normal_FABS(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FABS();
    NEXT();
}

void OPCALL normal_FTST(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FTST();
    NEXT();
}

void OPCALL normal_FXAM(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FXAM();
    NEXT();
}

void OPCALL normal_FLD1(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD1();
    NEXT();
}

void OPCALL normal_FLDL2T(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLDL2T();
    NEXT();
}

void OPCALL normal_FLDL2E(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLDL2E();
    NEXT();
}

void OPCALL normal_FLDPI(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLDPI();
    NEXT();
}

void OPCALL normal_FLDLG2(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLDLG2();
    NEXT();
}

void OPCALL normal_FLDLN2(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLDLN2();
    NEXT();
}

void OPCALL normal_FLDZ(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLDZ();
    NEXT();
}

void OPCALL normal_F2XM1(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.F2XM1();
    NEXT();
}

void OPCALL normal_FYL2X(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FYL2X();
    NEXT();
}

void OPCALL normal_FPTAN(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FPTAN();    
    NEXT();
}

void OPCALL normal_FPATAN(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FPATAN();
    NEXT();
}

void OPCALL normal_FXTRACT(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FXTRACT();
    NEXT();
}

void OPCALL normal_FPREM(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FPREM();
    NEXT();
}

void OPCALL normal_FPREM_nearest(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FPREM1();
    NEXT();
}

void OPCALL normal_FDECSTP(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FDECSTP();
    NEXT();
}

void OPCALL normal_FINCSTP(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FINCSTP();
    NEXT();
}

void OPCALL normal_FYL2XP1(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FYL2XP1();
    NEXT();
}

void OPCALL normal_FSQRT(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSQRT();
    NEXT();
}

void OPCALL normal_FSINCOS(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSINCOS();
    NEXT();
}

void OPCALL normal_FRNDINT(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FRNDINT();
    NEXT();
}

void OPCALL normal_FSCALE(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSCALE();
    NEXT();
}

void OPCALL normal_FSIN(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSIN();
    NEXT();
}

void OPCALL normal_FCOS(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCOS();
    NEXT();
}

void OPCALL normal_FST_STi(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FST_STi_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FIADD_DWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FADD_EA();
    NEXT();
}

void OPCALL normal_FIMUL_DWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FMUL_EA();
    NEXT();
}

void OPCALL normal_FICOM_DWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FCOM_EA();
    NEXT();
}

void OPCALL normal_FICOM_DWORD_INTEGER_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FCOM_EA();
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FISUB_DWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FSUB_EA();
    NEXT();
}

void OPCALL normal_FISUBR_DWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FSUBR_EA();
    NEXT();
}

void OPCALL normal_FIDIV_DWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FDIV_EA();
    NEXT();
}

void OPCALL normal_FIDIVR_DWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I32_EA(cpu, eaa(cpu, op));
    cpu->fpu.FDIVR_EA();
    NEXT();
}

void OPCALL normal_FCMOV_ST0_STj_CF(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    if (cpu->getCF())
        cpu->fpu.FST(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FCMOV_ST0_STj_ZF(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    if (cpu->getZF())
        cpu->fpu.FST(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FCMOV_ST0_STj_CF_OR_ZF(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    if (cpu->getCF() || cpu->getZF())
        cpu->fpu.FST(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FCMOV_ST0_STj_PF(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    if (cpu->getPF())
        cpu->fpu.FST(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FCMOV_ST0_STj_NCF(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    if (!cpu->getCF())
        cpu->fpu.FST(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FCMOV_ST0_STj_NZF(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    if (!cpu->getZF())
        cpu->fpu.FST(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FCMOV_ST0_STj_NCF_AND_NZF(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    if (!cpu->getCF() && !cpu->getZF())
        cpu->fpu.FST(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FCMOV_ST0_STj_NPF(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    if (!cpu->getPF())
        cpu->fpu.FST(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FUCOMPP(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FUCOM(cpu->fpu.STV(0), cpu->fpu.STV(1));
    cpu->fpu.FPOP();
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FILD_DWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    U32 value = readd(eaa(cpu, op)); // might generate PF, so do before we adjust the stack
    cpu->fpu.PREP_PUSH();
    cpu->fpu.FLD_I32(value, cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FISTTP32(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSTT_I32(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FIST_DWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_I32(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FIST_DWORD_INTEGER_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_I32(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FLD_EXTENDED_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    U32 address = eaa(cpu, op);
    U64 low = readq(address); // might generate PF, so do before we adjust the stack
    U32 high = readw(address + 8);
    cpu->fpu.PREP_PUSH();
    cpu->fpu.FLD_F80(low, high);
    NEXT();
}

void OPCALL normal_FSTP_EXTENDED_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_F80(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FNCLEX(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCLEX();
    NEXT();
}

void OPCALL normal_FNINIT(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FINIT();
    NEXT();
}

// Quiet compare
void OPCALL normal_FUCOMI_ST0_STj(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCOMI(cpu, cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FUCOMI_ST0_STj_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCOMI(cpu, cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    cpu->fpu.FPOP();
    NEXT();
}

// Signaling compare :TODO:
void OPCALL normal_FCOMI_ST0_STj(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCOMI(cpu, cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FCOMI_ST0_STj_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCOMI(cpu, cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FADD_DOUBLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F64_EA(cpu, eaa(cpu, op));
    cpu->fpu.FADD_EA();
    NEXT();
}

void OPCALL normal_FMUL_DOUBLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F64_EA(cpu, eaa(cpu, op));
    cpu->fpu.FMUL_EA();
    NEXT();
}

void OPCALL normal_FCOM_DOUBLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F64_EA(cpu, eaa(cpu, op));
    cpu->fpu.FCOM_EA();
    NEXT();
}

void OPCALL normal_FCOM_DOUBLE_REAL_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F64_EA(cpu, eaa(cpu, op));
    cpu->fpu.FCOM_EA();
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FSUB_DOUBLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F64_EA(cpu, eaa(cpu, op));
    cpu->fpu.FSUB_EA();
    NEXT();
}

void OPCALL normal_FSUBR_DOUBLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F64_EA(cpu, eaa(cpu, op));
    cpu->fpu.FSUBR_EA();
    NEXT();
}

void OPCALL normal_FDIV_DOUBLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F64_EA(cpu, eaa(cpu, op));
    cpu->fpu.FDIV_EA();
    NEXT();
}

void OPCALL normal_FDIVR_DOUBLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_F64_EA(cpu, eaa(cpu, op));
    cpu->fpu.FDIVR_EA();
    NEXT();
}

void OPCALL normal_FADD_STi_ST0(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FADD(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FADD_STi_ST0_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FADD(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FMUL_STi_ST0(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FMUL(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FMUL_STi_ST0_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FMUL(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FSUBR_STi_ST0(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSUBR(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FSUBR_STi_ST0_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSUBR(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FSUB_STi_ST0(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSUB(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FSUB_STi_ST0_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSUB(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FDIVR_STi_ST0(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FDIVR(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FDIVR_STi_ST0_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FDIVR(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FDIV_STi_ST0(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FDIV(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FDIV_STi_ST0_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FDIV(cpu->fpu.STV(op->reg), cpu->fpu.STV(0));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FLD_DOUBLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    U64 value = readq(eaa(cpu, op)); // might generate PF, so do before we adjust the stack
    cpu->fpu.PREP_PUSH();
    cpu->fpu.FLD_F64(value, cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FISTTP64(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSTT_I64(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FST_DOUBLE_REAL(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_F64(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FST_DOUBLE_REAL_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_F64(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FRSTOR(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FRSTOR(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FNSAVE(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSAVE(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FNSTSW(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    writew(eaa(cpu, op), cpu->fpu.SW());
    NEXT();
}

void OPCALL normal_FFREE_STi(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FFREE_STi(cpu->fpu.STV(op->reg));
    NEXT();
}

void OPCALL normal_FUCOM_STi(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FUCOM(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));    
    NEXT();
}

void OPCALL normal_FUCOM_STi_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FUCOM(cpu->fpu.STV(0), cpu->fpu.STV(op->reg));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FIADD_WORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I16_EA(cpu, eaa(cpu, op));
    cpu->fpu.FADD_EA();
    NEXT();
}

void OPCALL normal_FIMUL_WORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I16_EA(cpu, eaa(cpu, op));
    cpu->fpu.FMUL_EA();
    NEXT();
}

void OPCALL normal_FICOM_WORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I16_EA(cpu, eaa(cpu, op));
    cpu->fpu.FCOM_EA();
    NEXT();
}

void OPCALL normal_FICOM_WORD_INTEGER_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I16_EA(cpu, eaa(cpu, op));
    cpu->fpu.FCOM_EA();
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FISUB_WORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I16_EA(cpu, eaa(cpu, op));
    cpu->fpu.FSUB_EA();
    NEXT();
}

void OPCALL normal_FISUBR_WORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I16_EA(cpu, eaa(cpu, op));
    cpu->fpu.FSUBR_EA();
    NEXT();
}

void OPCALL normal_FIDIV_WORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I16_EA(cpu, eaa(cpu, op));
    cpu->fpu.FDIV_EA();
    NEXT();
}

void OPCALL normal_FIDIVR_WORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FLD_I16_EA(cpu, eaa(cpu, op));
    cpu->fpu.FDIVR_EA();
    NEXT();
}

void OPCALL normal_FCOMPP(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FCOM(cpu->fpu.STV(0), cpu->fpu.STV(1));
    cpu->fpu.FPOP();
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FILD_WORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    S16 value = (S16)readw(eaa(cpu, op)); // might generate PF, so do before we adjust the stack
    cpu->fpu.PREP_PUSH();
    cpu->fpu.FLD_I16(value, cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FISTTP16(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FSTT_I16(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FIST_WORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_I16(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FIST_WORD_INTEGER_Pop(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_I16(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void normal_FBLD_PACKED_BCD(CPU* cpu, U32 address) {
    U8 value[10];
    readMemory(value, address, 10); // might generate PF, so do before we adjust the stack
    cpu->fpu.PREP_PUSH();
    cpu->fpu.FBLD(value, cpu->fpu.STV(0));
}

void OPCALL normal_FBLD_PACKED_BCD(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    normal_FBLD_PACKED_BCD(cpu, eaa(cpu, op));
    NEXT();
}

void OPCALL normal_FILD_QWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    U64 value = readq(eaa(cpu, op)); // might generate PF, so do before we adjust the stack
    cpu->fpu.PREP_PUSH();
    cpu->fpu.FLD_I64(value, cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FILD_QWORD_INTEGER_32(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    U64 value = readq(eaa(cpu, op)); // might generate PF, so do before we adjust the stack
    cpu->fpu.PREP_PUSH();
    cpu->fpu.FLD_I64(value, cpu->fpu.STV(0));
    NEXT();
}

void OPCALL normal_FBSTP_PACKED_BCD(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FBST(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FISTP_QWORD_INTEGER(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FST_I64(cpu, eaa(cpu, op));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FFREEP_STi(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    cpu->fpu.FFREE_STi(cpu->fpu.STV(op->reg));
    cpu->fpu.FPOP();
    NEXT();
}

void OPCALL normal_FNSTSW_AX(CPU* cpu, DecodedOp* op) {
    START_OP(cpu, op);
    AX = cpu->fpu.SW();
    NEXT();
}