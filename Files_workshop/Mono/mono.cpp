/* ------------------------------------------------------------
name: "code", "FaustDSP"
Code generated with Faust 2.23.2 (https://faust.grame.fr)
Compilation options: -lang cpp -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>

static float mydsp_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fRec2[2];
	FAUSTFLOAT fButton0;
	float fRec3[2];
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	float fConst2;
	FAUSTFLOAT fHslider2;
	float fRec7[2];
	float fRec5[2];
	float fVec0[2];
	float fRec1[2];
	float fRec0[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compilation_options", "-single -scal -I libraries/ -I project/ -lang wasm");
		m->declare("filename", "code.dsp");
		m->declare("filters_lib_fir_author", "Julius O. Smith III");
		m->declare("filters_lib_fir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_fir_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_iir_author", "Julius O. Smith III");
		m->declare("filters_lib_iir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_iir_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_lowpass0_highpass1_author", "Julius O. Smith III");
		m->declare("filters_lib_lowpass_author", "Julius O. Smith III");
		m->declare("filters_lib_lowpass_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_lowpass_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_name", "Faust Filters Library");
		m->declare("filters_lib_tf1_author", "Julius O. Smith III");
		m->declare("filters_lib_tf1_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_tf1_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_tf1s_author", "Julius O. Smith III");
		m->declare("filters_lib_tf1s_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_tf1s_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_tf2_author", "Julius O. Smith III");
		m->declare("filters_lib_tf2_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_tf2_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_tf2s_author", "Julius O. Smith III");
		m->declare("filters_lib_tf2s_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_tf2s_license", "MIT-style STK-4.3 license");
		m->declare("library_path", "FaustDSP");
		m->declare("maths_lib_author", "GRAME");
		m->declare("maths_lib_copyright", "GRAME");
		m->declare("maths_lib_license", "LGPL with exception");
		m->declare("maths_lib_name", "Faust Math Library");
		m->declare("maths_lib_version", "2.1");
		m->declare("name", "code");
		m->declare("oscillators_lib_name", "Faust Oscillator Library");
		m->declare("oscillators_lib_version", "0.0");
		m->declare("signals_lib_name", "Faust Signal Routing Library");
		m->declare("signals_lib_version", "0.0");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (1.0f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(10000.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.10000000000000001f);
		fHslider2 = FAUSTFLOAT(100.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec2[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec4[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec7[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec0[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec1[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec0[l7] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("code");
		ui_interface->addHorizontalSlider("cutoff", &fHslider0, 10000.0f, 50.0f, 10000.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("freq", &fHslider2, 100.0f, 50.0f, 200.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("gain", &fHslider1, 0.100000001f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (0.00100000005f * float(fHslider0));
		float fSlow1 = (0.00100000005f * float(fButton0));
		float fSlow2 = (0.00100000005f * float(fHslider1));
		float fSlow3 = (0.00100000005f * float(fHslider2));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec2[0] = (fSlow0 + (0.999000013f * fRec2[1]));
			float fTemp0 = std::tan((fConst1 * fRec2[0]));
			float fTemp1 = (1.0f / fTemp0);
			fRec3[0] = (fSlow1 + (0.999000013f * fRec3[1]));
			fRec4[0] = (fSlow2 + (0.999000013f * fRec4[1]));
			fRec7[0] = (fSlow3 + (0.999000013f * fRec7[1]));
			float fTemp2 = std::max<float>(1.00000001e-07f, std::fabs(fRec7[0]));
			float fTemp3 = (fRec5[1] + (fConst2 * fTemp2));
			float fTemp4 = (fTemp3 + -1.0f);
			int iTemp5 = (fTemp4 < 0.0f);
			fRec5[0] = (iTemp5 ? fTemp3 : fTemp4);
			float fRec6 = (iTemp5 ? fTemp3 : (fTemp3 + ((1.0f - (fConst0 / fTemp2)) * fTemp4)));
			float fTemp6 = ((fRec3[0] * fRec4[0]) * ((2.0f * fRec6) + -1.0f));
			fVec0[0] = fTemp6;
			fRec1[0] = (0.0f - (((fRec1[1] * (1.0f - fTemp1)) - (fTemp6 + fVec0[1])) / (fTemp1 + 1.0f)));
			float fTemp7 = (((fTemp1 + 1.0f) / fTemp0) + 1.0f);
			fRec0[0] = (fRec1[0] - (((fRec0[2] * (((fTemp1 + -1.0f) / fTemp0) + 1.0f)) + (2.0f * (fRec0[1] * (1.0f - (1.0f / mydsp_faustpower2_f(fTemp0)))))) / fTemp7));
			float fTemp8 = ((fRec0[2] + (fRec0[0] + (2.0f * fRec0[1]))) / fTemp7);
			output0[i] = FAUSTFLOAT(fTemp8);
			output1[i] = FAUSTFLOAT(fTemp8);
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec7[1] = fRec7[0];
			fRec5[1] = fRec5[0];
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
