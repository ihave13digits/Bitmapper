class Noise
{

public:

    int seed;
    std::vector<float> noise;

    void SeedNoise(uint8_t octaves, float a=0.0, float b=100.0, float s=0) { for (int n = 1; n < octaves; n ++) { float r = ((float(rand()%1000)*0.001)*b)+a; noise.push_back(r); } noise.push_back(noise[0]); }

    void ExpandNoise(float lerp)
    {
        std::vector<float> _noise;
        for (int s = 0; s < noise.size(); s++)
        {
            float a = noise[s];
            _noise.push_back(a); _noise.push_back(a);
        }
        noise = _noise;
    }

    void InterpolateNoise(float lerp)
    {
        float _lerp = 1.0-lerp; std::vector<float> _noise;
        for (int i = 0; i < noise.size(); i++)
        {
            if (i == 0) { float n = (noise[i]*_lerp)+(noise[noise.size()-1]*lerp); _noise.push_back(n); }
            if (i > 0) { float n = (noise[i]*_lerp)+(noise[i-1]*lerp); _noise.push_back(n); }
        }
        noise = _noise;
    }

    void GenerateNoise(uint16_t points, int space, float lerp, float a, float b, int s=0)
    { seed = s; srand(seed); SeedNoise(points, a, b); while (noise.size() < space) { ExpandNoise(lerp); InterpolateNoise(lerp); InterpolateNoise(lerp); }}

};

namespace chaotic
{

    int seed;
    std::vector<float> noise;
    
    //

    int Int(int i) { return rand()%i; }
    bool Chance(float c) { return ((float(rand()%100000)*0.001) < c); }
    float Range(float a, float b) { return ((float(rand()%100000)*0.00001)*b)+a; }

    void GenerateNoise(int s=0, uint16_t octaves=32, int space=4096, float lerp=0.5)
    {
        seed = s; srand(seed);
        float l = lerp;
        float _l = 1.0-lerp;
        std::vector<float> _noise;
        for (int i = 1; i < octaves/2+1; i++)
        {
            float bias = 1.0-(float(i)/float(octaves/2));
            float l = bias;
            float _l = 1.0-bias;
            Noise n = Noise(); n.GenerateNoise(octaves-(i+i%1), space, lerp, bias, 1.0, seed+i);
            for (int ni = 0; ni < n.noise.size(); ni++)
            {
                if (noise.size() == n.noise.size()) { _noise.push_back((n.noise[ni]*l)+(noise[ni]*_l)); }
                else { _noise.push_back(n.noise[ni]); }
            }
            noise = _noise; _noise.clear();
        }
    }

}
