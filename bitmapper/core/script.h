class Script
{

public:

    enum OPS {
        oPLUS,
        oMINUS,
        oGREATER,
        oEQUAL,
        oLESSER,
        oBRACKET_L,
        oBRACKET_R,
    };

    enum FUNC {
        //
        /// Tile Tool
        //
        
        //
        fGET_TYPE,
        fGET_DURABILITY,
        //
        fGET_LIGHT_VALUE,
        fNEIGHBORS,
        //
        fGAS_COLLISION,
        fFUME_COLLISION,
        fFLUID_COLLISION,
        fGEL_COLLISION,
        fGRAIN_COLLISION,
        fDUAL_COLLISION,
        fIS_COLLIDING,
        fCOLLISION,
        //
        fSET,
        fSWAP,
        fSOFT_SWAP,
    };

    std::vector<std::string> func = {
        "get_type",
        "get_durability",
        "get_light_value",
        "neighbors",
        "gas_collision",
        "fume_collision",
        "fluid_collision",
        "gel_collision",
        "grain_collision",
        "dual_collision",
        "is_colliding",
        "collision",
        "set",
        "swap",
        "soft_swap",
    };

};
