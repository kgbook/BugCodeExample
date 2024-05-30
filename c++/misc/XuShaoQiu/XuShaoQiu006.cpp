#include<iostream>

struct NLAData {
    uint32_t u32Point0;
    uint32_t u32Point25;
    uint32_t u32Point50;
    uint32_t u32Point75;
    uint32_t u32Point100;
};

NLAData nlaData;

void mw2SdkNonLinear(uint32_t input, uint32_t *output) {
    double slopValue;
    uint32_t diffValue;
    uint32_t baseValue;
    if (75 < input) {
        slopValue = (int32_t) (nlaData.u32Point100 - nlaData.u32Point75) / 25.0;
        diffValue = input - 75;
        baseValue = nlaData.u32Point75;
    } else if (50 < input) {
        slopValue = (int32_t) (nlaData.u32Point75 - nlaData.u32Point50) / 25.0;
        diffValue = input - 50;
        baseValue = nlaData.u32Point50;
    } else if (25 < input) {
        slopValue = (int32_t) (nlaData.u32Point50 - nlaData.u32Point25) / 25.0;
        diffValue = input - 25;
        baseValue = nlaData.u32Point25;
    } else {
        slopValue = (int32_t) (nlaData.u32Point25 - nlaData.u32Point0) / 25.0;
        diffValue = input - 0;
        baseValue = nlaData.u32Point0;
    }

    *output = baseValue + (int32_t) (slopValue * diffValue);
}

void sdk2MwNonLinear(uint32_t input, uint32_t *output) {
    double slopValue;
    uint32_t diffValue;
    uint32_t baseValue;
    if (nlaData.u32Point75 < input) {
        if (nlaData.u32Point100 != nlaData.u32Point75) {
            slopValue = 25.0 / (int32_t) (nlaData.u32Point100 - nlaData.u32Point75);
        } else {
            slopValue = 0;
        }
        diffValue = input - nlaData.u32Point75;
        baseValue = 75;
    } else if (nlaData.u32Point50 < input) {
        if (nlaData.u32Point75 != nlaData.u32Point50) {
            slopValue = 25.0 / (int32_t) (nlaData.u32Point75 - nlaData.u32Point50);
        } else {
            slopValue = 0;
        }
        diffValue = input - nlaData.u32Point50;
        baseValue = 50;
    } else if (nlaData.u32Point25 < input) {
        if (nlaData.u32Point50 != nlaData.u32Point25) {
            slopValue = 25.0 / (int32_t) (nlaData.u32Point50 - nlaData.u32Point25);
        } else {
            slopValue = 0;
        }
        diffValue = input - nlaData.u32Point25;
        baseValue = 25;
    } else {
        if (nlaData.u32Point25 != nlaData.u32Point0) {
            slopValue = 25.0 / (int32_t) (nlaData.u32Point25 - nlaData.u32Point0);
        } else {
            slopValue = 0;
        }
        diffValue = input - nlaData.u32Point0;
        baseValue = 0;
    }

    *output = baseValue + (int32_t) (slopValue * diffValue);
}

int main() {
    nlaData.u32Point0 = 64;
    nlaData.u32Point25 = 110;
    nlaData.u32Point50 = 157;
    nlaData.u32Point75 = 205;
    nlaData.u32Point100 = 255;

    uint32_t input;
    uint32_t output;

    for (uint32_t i = 0; i <= 100; i++) {
        input = i;
        mw2SdkNonLinear(input, &output);
        printf("mw2SdkNonLinear: input %d,output %d\n", input, output);
        sdk2MwNonLinear(output, &input);
        printf("mw2SdkNonLinear: input %d,output %d\n", output, input);
        if (input != i) {
            printf("revert failed for %d\n", i);
        }
    }
    return 0;
}