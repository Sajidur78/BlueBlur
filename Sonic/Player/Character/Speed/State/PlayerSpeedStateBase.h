#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachine.h>
#include <Sonic/Player/Character/Speed/PlayerSpeedContext.h>

namespace Sonic::Player
{
    class CPlayerSpeedContext::CStateSpeedBase : public Hedgehog::Universe::TStateMachine<CPlayerContext>::TState
    {
    public:
        BB_INSERT_PADDING(0x8);

        static inline uint32_t pCtor = 0xE497E0;

        static void fCtor(CStateSpeedBase* This)
        {
            __asm
            {
                mov edi, This
                call [pCtor]
            }
        }

        CStateSpeedBase(const bb_null_ctor& nil) : TState(nil) {}

        CStateSpeedBase() : CStateSpeedBase(bb_null_ctor{})
        {
            fCtor(this);
        }

        CPlayerSpeedContext* GetContext() const
        {
            return static_cast<CPlayerSpeedContext*>(m_pContext);
        }

        virtual void ProcMsgOnGround() {}
    };

    BB_ASSERT_SIZEOF(CPlayerSpeedContext::CStateSpeedBase, 0x68);
}