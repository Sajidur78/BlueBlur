﻿#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>

namespace Chao::CSD
{
    struct Project;
    class CProject;
    class CScene;
    
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCProjectGetScene, 0x677220,
        const CProject* This, RCPtr<CScene>& out_rcScene, const char* in_pName, size_t in_Group);

    class CProject : public CResourceBase<Project>, CBase
    {
    public:
        BB_INSERT_PADDING(0x40);

        RCPtr<CScene> GetScene(const char* in_pName, size_t in_Group) const
        {
            RCPtr<CScene> rcScene;
            fpCProjectGetScene(this, rcScene, in_pName, in_Group);
            return rcScene;
        }
    };

    BB_ASSERT_SIZEOF(CProject, 0x50);
}