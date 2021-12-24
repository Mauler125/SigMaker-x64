#include "Misc.h"

Settings_t Settings;

void Settings_t::Init( void )
{
    memset( this, 0, sizeof( Settings_t ) );
    Settings.iLogLevel = 1;
}

void Settings_t::Save( const char* pszFileName )
{
    char szLocation[MAXSTR];

    qsnprintf( szLocation, MAXSTR - 1, "%s\\%s", get_user_idadir( ), pszFileName );

    if (Settings.iLogLevel >= 3)
    {
        msg( "Saving settings to %s\n", szLocation );
    }

    FILE* pFile = qfopen( szLocation, "wb" );

    if (pFile)
    {
        qfwrite( pFile, this, sizeof( Settings_t ) );
        qfclose( pFile );
    }
}

void Settings_t::Load( const char* pszFileName )
{
    char szLocation[MAXSTR];

    qsnprintf( szLocation, MAXSTR - 1, "%s\\%s", get_user_idadir( ), pszFileName );

    if (Settings.iLogLevel >= 3)
    {
        msg( "Loading settings from %s\n", szLocation );
    }

    FILE* pFile = qfopen( szLocation, "rb" );
    if (pFile)
    {
        qfread( pFile, this, sizeof( Settings_t ) );
        qfclose( pFile );
    }
    else
    {
        if (Settings.iLogLevel >= 2)
            msg( "Couldn't open settings file. Using either default or current settings\n" );
    }
}