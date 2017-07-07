// Copyright (c) 2017 The Bitcoin Unlimited Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BUIP055FORK_H
#define BUIP055FORK_H

// OP_RETURN magic invalid value:
extern std::vector<unsigned char> invalidOpReturn;

// Validate that the block's contents adhere to the BUIP055 hard fork requirements.
// the requirement that the fork block is >= 1MB is not checked because we do not
// know whether this is the fork block.
extern bool ValidateBUIP055Block(const CBlock &block, CValidationState &state);

// Validate that a transaction adheres to the BUIP055 hard fork requirements.
extern bool ValidateBUIP055Tx(const CTransaction& tx);

// Return true if this transaction is invalid on the BUIP055 fork due to a special OP_RETURN code
extern bool IsTxOpReturnInvalid(const CTransaction &tx);

// Update global variables based on whether the next block is the fork block
extern bool UpdateBUIP055Globals(CBlockIndex *activeTip);

extern CTweak<uint64_t> miningForkTime;
extern CTweak<uint64_t> miningForkEB;
extern CTweak<uint64_t> miningForkMG;

#endif
