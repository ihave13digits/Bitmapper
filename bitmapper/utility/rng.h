namespace random
{
    bool Chance(float c) { return ((float(rand()%100000)*0.001) < c); }
    int Int(int i) { return rand()%i; }
}
