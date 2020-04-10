import ("stdfaust.lib");

f = hslider("freq", 200, 50, 100, 0.01): si.smoo;
g = hslider("gain", 0.1,0,1,0.01): si.smoo;
t = button("gate"): si.smoo;
ct = hslider("cutoff",10000,50,10000,0.01): si.smoo;
process  =os.sawtooth(f)*t*g :fi.lowpass(3,ct)<:_,_;
