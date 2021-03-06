/************************************************************
 *
 *  main.cpp
 *
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
**************************************************************/

#include <opentxs/core/Version.hpp>
#include <opentxs/api/OT.hpp>
#include <opentxs/cash/Mint.hpp>
#include <opentxs/core/util/OTDataFolder.hpp>
#include <opentxs/core/util/OTFolders.hpp>
#include <opentxs/core/util/OTPaths.hpp>
#include <opentxs/core/Log.hpp>
#include <opentxs/core/OTStorage.hpp>
#include <opentxs/server/OTServer.hpp>

#include <cstdio>
#include <string>
#include <map>

extern "C" {
#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#endif
}

#include <time.h>
#include <assert.h>

// TODO: what about android for all the defaults here? Are there ini files in
// android? Revisit.
// so far, treating it like unix since it is.
//
// Paths
//

#define SERVER_PATH_DEFAULT "server_data" // should get programmatically
#define SERVER_CONFIG_KEY "server"
#define SERVER_CONFIG_FILENAME "server.cfg"
#define SERVER_LOGFILE_FILENAME "log-server.log"
#define SERVER_MASTER_KEY_TIMEOUT_DEFAULT -1
#define SERVER_MAIN_FILENAME "notaryServer.xml"

#define KEY_PASSWORD "test"
//#define KEY_PASSWORD        ""

using namespace opentxs;

int main(int argc, char* const argv[])
{
    if (argc > 1) {
        std::string arg(argv[1]);
        if (arg.compare("version") == 0 || arg.compare("--version") == 0) {
            otOut << "opentxs server " << OPENTXS_SERVER_VERSION_STRING << "\n";
            otOut << "opentxs library " << OPENTXS_VERSION_STRING << "\n";
            otOut << "Copyright (C) 2014 Open Transactions Developers\n";
            return 0;
        }
    }

    if (argc < 4) {
        printf("\n\nUsage:  createmint  server_id  server_user_id  "
               "asset_type_id \n\n"
               "For now, expiration dates are automatically set:\n"
               "-- FROM: Today, Now.\n"
               "-- TO: 6 months from now.\n\n"
               "It is recommended that you issue a new series (create a new "
               "mint) every 3 months for each\n"
               "asset type, so that there is a 3-month overlap. In the future, "
               "this will be configured inside\n"
               "the contracts themselves.\n\n"
               "Server ID needs to match the Server ID from notaryServer.xml\n"
               "Server user ID needs to match the Server User ID from "
               "notaryServer.xml\n"
               "Asset Type ID needs to match the Asset ID (aka Hashed Contract "
               "ID) of the currency contract.\n\n"
               //               "The path to the data folder is necessary for
               // initialization of the OT library.\n\n"
               //             "(You probably want to use ~/.ot/server_data as
               // your data folder.)\n\n"
               );
        return 0;
    }
    // **************************************************************************

    class OTcreatemint_RAII
    {
    private:
        std::unique_ptr<AppLoader> app_;

    public:
        OTcreatemint_RAII()
        {
            if (!Log::Init(SERVER_CONFIG_KEY, 0)) {
                assert(false);
            }; // setup the logger.

            Log::vOutput(0, "\n\nWelcome to Open Transactions -- "
                            "'createmint', version %s\n",
                         Log::Version());
#ifdef _WIN32
            WSADATA wsaData;
            WORD wVersionRequested = MAKEWORD(2, 2);
            int err = WSAStartup(wVersionRequested, &wsaData);

            /* Tell the user that we could not find a usable        */
            /* Winsock DLL.                                            */

            OT_ASSERT_MSG((err == 0), "WSAStartup failed!\n");

            /*    Confirm that the WinSock DLL supports 2.2.            */
            /*    Note that if the DLL supports versions greater        */
            /*    than 2.2 in addition to 2.2, it will still return    */
            /*    2.2 in wVersion since that is the version we        */
            /*    requested.                                            */

            bool bWinsock = (LOBYTE(wsaData.wVersion) != 2 ||
                             HIBYTE(wsaData.wVersion) != 2);

            /* Tell the user that we could not find a usable */
            /* WinSock DLL.                                  */

            if (!bWinsock) WSACleanup(); // do cleanup.
            OT_ASSERT_MSG((!bWinsock),
                          "Could not find a usable version of Winsock.dll\n");

            /* The Winsock DLL is acceptable. Proceed to use it. */
            /* Add network programming using Winsock here */
            /* then call WSACleanup when done using the Winsock dll */
            Log::vOutput(0, "The Winsock 2.2 dll was found okay\n");
#endif
// SIGNALS
//
#if defined(OT_SIGNAL_HANDLING)
            //
            Log::SetupSignalHandler(); // <===== SIGNALS
                                       //
// This is optional! You can always remove it using the OT_NO_SIGNAL_HANDLING
//  option, and plus, the internals only execute once anyway. (It keeps count.)
#endif

            //
            // OT Server Path:
            //
            {
                bool bSetupPathsSuccess = false;
                if (!OTDataFolder::Init(SERVER_CONFIG_KEY)) {
                    OT_FAIL;
                }
                else
                    bSetupPathsSuccess = true;

                OT_ASSERT_MSG(bSetupPathsSuccess,
                              "main(): Assert failed: Failed to set OT Path");
            }

            app_.reset(new AppLoader);
        }
        ~OTcreatemint_RAII()
        {
            // We clean these up in reverse order from the Init function, which
            // just seems
            // like the best default, in absence of any brighter ideas.
            //
            app_.reset();

#ifdef _WIN32
            WSACleanup(); // Corresponds to WSAStartup() in InitOTAPI().
#endif
        }
    };

    OTcreatemint_RAII the_createmint_cleanup;

    // **************************************************************************

    OTServer theServer;

    int nReturnVal = 1;

    String strServerID(argv[1]), strServerNymID(argv[2]),
        strAssetTypeID(argv[3]);

    Identifier ASSET_TYPE_ID(strAssetTypeID), SERVER_ID(strServerID);

    //    std::string strDataFolderPath(argv[4]),
    // strNotaryFile("notaryServer.xml");

    Log::vOutput(0, "\nNow loading the server nym, which will also ask you "
                    "for a password, to unlock\n"
                    "its private key. (Default password is \"%s\".)\n",
                 KEY_PASSWORD);

    std::map<std::string, std::string> args;

    // Keys, etc are loaded here. ===> Assumes main path is set! <===
    //
    theServer.Init(args, true); // bool bReadOnly=false by default (We don't want to
                          // overwrite anything if the ACTUAL server is
                          // running...)

    //  NOTE: I copied some code in here from xmlrpcxx_server.cpp, including the
    // above
    //  call to theServer.Init(), which has the InitDefaultStorage inside of it,
    // and
    //  which uses Log::Path(), which the above new code should be setting
    // properly
    //  before theServer.Init() actually gets called. (So this should work....)
    //
    //    bool bSuccessInitDefault =
    // OTDB::InitDefaultStorage(OTDB_DEFAULT_STORAGE,
    //                                                        OTDB_DEFAULT_PACKER,
    // strDataFolderPath, strNotaryFile);
    //    if (!bSuccessInitDefault)
    //    {
    //        Log::vError("\n\n%s: Failed invoking OTDB::InitDefaultStorage
    // with path: %s and main filename: %s\n\n",
    //                      __FUNCTION__, strDataFolderPath.c_str(),
    // strNotaryFile.c_str());
    //        return 0;
    //    }

    String strMintPath;
    bool bFileIsPresent = false;
    int nSeries = 0;

    for (nSeries = 0; nSeries < 10000; ++nSeries) {
        //        struct stat st;

        String strFilename;
        strFilename.Format("%s%s%d", strAssetTypeID.Get(), ".", nSeries);

        bFileIsPresent = OTDB::Exists(OTFolders::Mint().Get(),
                                      strServerID.Get(), strFilename.Get());

        // Old Code
        // strMintPath.Format("%s%s%s%s%s%s%s%s%d",
        //    Log::Path(),
        //    Log::PathSeparator(),
        //    OTFolders::Mint().Get(),
        //    Log::PathSeparator(),
        //    strServerID.Get(),
        //    Log::PathSeparator(),
        //    strAssetTypeID.Get(), ".", nSeries);
        // bFileIsPresent = (stat(strMintPath.Get(), &st) == 0);

        if (!bFileIsPresent) break;
    }

    // if bFileIsPresent is STILL true, that means we got all the way up to 1000
    // and the
    // file was present every time.
    // Geez, there must be 10000 mints on this computer.  At one new Mint per 3
    // months,
    // that's 4 per year, that's 2500 years already!!
    //
    if (bFileIsPresent) {
        Log::Output(0, "\n\nThis program automatically finds the next "
                       "series, up to 10000. You\n"
                       "have reached 10000. You will have to change the "
                       "source code of this\n"
                       "program in order to continue. Sorry.\n\n");
        return 0;
    }

    // nSeries now contains the number we need to use for the next series.
    // and strMintPath now contains the correct file path.

    Mint* pMint =
        Mint::MintFactory(strServerID, strServerNymID, strAssetTypeID);
    OT_ASSERT(nullptr != pMint);

    String strSeries;
    strSeries.Format("%s%d", ".", nSeries);

    if (pMint->LoadMint(strSeries.Get())) {
        Log::Output(0, "\n\nSorry, that mint already exists. Delete it first "
                       "if you wish to re-create it.\n\n");
    }
    else {
        Log::vOutput(0, "\n\nMint file does not (yet) exist for series %d "
                        "and asset type:\n%s\n Creating......\n\n",
                     nSeries, strAssetTypeID.Get());

        // TODO: read the denominations out of the asset contract itself,
        // instead of hardcoding them here.

        // Calculate FROM as Today, Now,
        // then calculate TO as 6 months from now,
        // and EXPIRATION as 3 months from now.
        //
        // TODO: Let these numbers be configured either in server operator
        // contract, or issuer contract.
        // In the meantime, 3 and 6 months are good enough.

        Nym theNym;
        theNym.SetIdentifier(strServerNymID);

        // 1 hour    ==     3600 Seconds
        // 1 day    ==    86400 Seconds
        // 30 days    ==  2592000 Seconds
        // 3 months ==  7776000 Seconds
        // 6 months == 15552000 Seconds

        // This part requires the server operator to enter his passphrase.
        // Which is why the server can't just fire it off automatically and
        // make a mint available to the client.  The client has to wait a day or
        // until the operator is able to run this script and type the
        // passphrase.
        if (theNym.LoadCredentials(true)) {
            const time64_t CURRENT_TIME = OTTimeGetCurrentTime(),
                           VALID_TO = OTTimeAddTimeInterval(
                               CURRENT_TIME,
                               OTTimeGetSecondsFromTime(
                                   OT_TIME_SIX_MONTHS_IN_SECONDS)), // Tokens
                                                                    // generated
                                                                    // by this
                                                                    // mint are
                                                                    // valid
                                                                    // from
                                                                    // today
                                                                    // until 6
                                                                    // months
                                                                    // from
                                                                    // today
                MINT_EXPIRATION = OTTimeAddTimeInterval(
                    CURRENT_TIME,
                    OTTimeGetSecondsFromTime(
                        OT_TIME_THREE_MONTHS_IN_SECONDS)); // The mint itself
                                                           // will expire in 3
                                                           // months from today,
                                                           // and be replaced
                                                           // with a new one.

            pMint->GenerateNewMint(
                nSeries, CURRENT_TIME, VALID_TO, MINT_EXPIRATION, ASSET_TYPE_ID,
                SERVER_ID,
                // penny, nickel, dime, quarter, $1, $5, $10, $20, $100, $1000
                theNym, 1, 5, 10, 25, 100, 500, 1000, 2000, 10000, 100000);
            // should be: 1, 2, 4,   8,  16,  32,   64,  128,   256,    512,
            // 1024, 2048, 4096, 8192, 16384, 32768, 65536

            //            OTString strFilename;// strPUBLICFilename;
            //            strFilename.        Format("%s%s%s",
            // strServerID.Get(), Log::PathSeparator(), strAssetTypeID.Get());
            //            strPUBLICFilename.
            // Format("%s%s%s%sPUBLIC",strServerID.Get(),
            // Log::PathSeparator(), strAssetTypeID.Get(), ".");

            if (!OTDataFolder::IsInitialized()) {
                OT_FAIL;
            }

            String strServerFolder(""), strMintFolder("");

            //            Log::vError("DEBUGGING: OTDataFolder::Get().Get():
            // %s \n", OTDataFolder::Get().Get());
            //            Log::vError("DEBUGGING: OTFolders::Mint().Get(): %s
            // \n",   OTFolders::Mint().Get());
            //            Log::vError("DEBUGGING: strServerID.Get(): %s \n",
            // strServerID.Get());

            if (!OTPaths::AppendFolder(strMintFolder, OTDataFolder::Get(),
                                       OTFolders::Mint())) {
                OT_FAIL;
            } // mint/
            if (!OTPaths::AppendFolder(strServerFolder, strMintFolder,
                                       strServerID.Get())) {
                OT_FAIL;
            } // mint/serverID

            bool bFolderCreated;
            if (OTPaths::BuildFolderPath(strServerFolder, bFolderCreated)) {
                // This causes the next serialization to save the private, not
                // just public, keys.
                pMint->SetSavePrivateKeys(); // <== PRIVATE MINT VERSION.

                pMint->SignContract(theNym);
                pMint->SaveContract();
                pMint->SaveMint(); // save the private mint file as:
                                   // path/mints/server_id/Asset_TypeID
                                   // (overwriting the last "current mint"...)
                pMint->SaveMint(
                    strSeries.Get()); // save the private mint file as:
                // path/mints/server_id/Asset_TypeID.nSeries
                // (These accumulate.)

                // When the server needs to reference the "current" private
                // keys, then it just loads the
                // mint without specifying the series number. Since this file is
                // overwritten with each new
                // mint, it is thus always the latest one.  (Similarly, the
                // latest public is always asset_id.PUBLIC)
                // On the other hand, if I need to load the keys for a specific
                // series, (since more than one may be
                // redeemable, even if only the latest one is being issued) then
                // they are all also saved by series
                // number, which is not overwritten with each new mint, but
                // accumulates.
                // That is why above, you see me save the mint twice in two
                // different files, and below you see
                // it being saved with the .PUBLIC appending to the filename.

                //                pMint->SaveContract(OTFolders::Mint().Get(),
                // strFilename.Get());  // save the mint file.

                // Now I sign it again, to get the private keys out of there.
                pMint->ReleaseSignatures();
                pMint->SignContract(theNym);
                pMint->SaveContract();
                pMint->SaveMint(".PUBLIC"); // save the public mint file.
                //                pMint->SaveContract(OTFolders::Mint().Get(),
                // strPUBLICFilename.Get());  // save the public mint file.

                nReturnVal = 0;

                Log::Output(0, "\nDone.\n\n");
            }
            else
                Log::Output(0, "\n\nError calling "
                               "Log::ConfirmOrCreateFolder() for "
                               "path/mints/server_id\n\n");
        }
        else
            Log::Output(0, "\n\nError calling "
                           "theNym.Loadx509CertAndPrivateKey(false)\n\n");
    } // Mint file doesn't exist yet (therefore the above block creates it...)

    return nReturnVal;
}
