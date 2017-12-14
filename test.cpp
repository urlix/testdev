#include <assert.h>
#include <map>
#include <limits>
#include <iostream>
#include <cstring>

static int		GbDisableHTML2TextProcessing;

char *
strfld( char *s, char *d )
{
	static char		*p = CNULL;
	char			*p1;

	if ( s )
		p = s;

	if ( !p || !d )
		return ( CNULL );

	#if III_CONF == III_ARETE
	if( !*p )
		{
		p1 = p;
		p = CNULL;
		return( p1 );
		}
	#endif

	p1 = p;

	if ( *d )
		if ( !*(d+1) )
		{
			if ( (p = strchr ( p1, *d ) ) )
				*p++ = '\0';
			return ( p1 );
		}

	if ( ( p = strpbrk ( p1, d ) ) )
		*p++ = '\0';

	return ( p1 );
}


char* strfld_r (char *s, char *d, char **p )
{
	char *p1;

	if ( s )
		*p = s;

	if ( !*p || !d )
		return ( NULL );

	p1 = *p;

	if ( *d )
		if ( !*(d+1) )
		{
			if ( ( *p = strchr ( p1, *d ) ) ) {
				**p = 0; ++*p;
			}
			return ( p1 );
		}

	if ( (*p = strpbrk ( p1, d ) ) ) {
		**p = 0; ++*p;
		}

	return ( p1 );
}

#define     LISTEND     "__listend__"
#define     MESGLISTEND         "__mesglistend__"
#define		HEXEND				"__hexend__"

int main() {

	char	ptr[] = "__listbegin__\\n\
@record_id=b-17\\n\
@read_status=\\n\
@write_status=\\n\
@end_directives\\n\
80:b\\n\
83:20171201112900\\n\
85:\\n\
81:\\n\
84:20171201112900\\n\
86:\\n\
82:\\n\
24:\\n\
28:\\n\
31:\\n\
25:.\\n\
29:\\n\
89:\\n\
26:\\n\
30:\\n\
107:\\n\
a:127:rrr\\n\
t:127:The%20some\\n\
__listend__\\n\

";
	char	*line = 0;
	char	*p = 0;
	char *delimiter = "\\n";

	strfld(ptr, delimiter)
/*
    for(;;)
	{
		if ((line = strfld_r(line ? NULL : ptr, delimiter, &p)) == NULL)
		{
			return -1;
		}

		if( strncmp( line, LISTEND, strlen(LISTEND) ) == 0 ||
		strncmp(line, MESGLISTEND, strlen(MESGLISTEND)) == 0 ||
		strncmp(line, HEXEND, strlen(HEXEND)) == 0)
		break;

		int len = (strlen(line) * 5) + 2;
		char* tmp = new char[len];

		html2text((char *) line, tmp, len);

		std::cout << tmp << std::endl;
	}
*/
	//std::cout << p << std::endl;
	return 0;
}