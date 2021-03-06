#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

typedef int bool;
#define true 1
#define false 0
// Max length of a token
#define MAX_WORD_LEN 50

typedef struct token {
	char value[MAX_WORD_LEN + 1];
	int code;
	int col;
	int row;
	struct token * next;
} Token;

Token * tokenize(char * filePath);

void printTokens();
void freeTokens();

void printToken(Token * token);


enum TOKEN_CODE {
// reserved words
ADD_TOKEN,
ALLOW_TOKEN,
ALTER_TOKEN,
AND_TOKEN,
OR_TOKEN,
APPLY_TOKEN,
ASC_TOKEN,
BATCH_TOKEN,
BEGIN_TOKEN,
BY_TOKEN,
CLUSTERING_TOKEN,
COLUMNFAMILY_TOKEN,
COMPACT_TOKEN,
COUNT_TOKEN,
COUNTER_TOKEN,
CREATE_TOKEN,
CUSTOM_TOKEN,
DELETE_TOKEN,
DESC_TOKEN,
DROP_TOKEN,
EXISTS_TOKEN,
FALSE_TOKEN,
FILTERING_TOKEN,
FROM_TOKEN,
IF_TOKEN,
IN_TOKEN,
TO_TOKEN,
INDEX_TOKEN,
INSERT_TOKEN,
INTO_TOKEN,
KEY_TOKEN,
KEYSPACE_TOKEN,
LIMIT_TOKEN,
LIST_TOKEN,
MAP_TOKEN,
NOT_TOKEN,
ON_TOKEN,
OPTIONS_TOKEN,
ORDER_TOKEN,
PRIMARY_TOKEN,
SELECT_TOKEN,
SET_TOKEN,
STATIC_TOKEN,
STORAGE_TOKEN,
TABLE_TOKEN,
TIMESTAMP_TOKEN,
TRUE_TOKEN,
TRUNCATE_TOKEN,
TTL_TOKEN,
TYPE_TOKEN,
UNLOGGED_TOKEN,
UPDATE_TOKEN,
USE_TOKEN,
USING_TOKEN,
VALUES_TOKEN,
WHERE_TOKEN,
WITH_TOKEN,
WRITETIME_TOKEN,
DISTINCT_TOKEN,
KEYS_TOKEN,
ENTRIES_TOKEN,
FULL_TOKEN,
DEFAULT_TOKEN,
UNSET_TOKEN,
AS_TOKEN,
TOKEN_TOKEN,
CONTAINS_TOKEN,
RENAME_TOKEN,
USER_TOKEN,
USERS_TOKEN,
PASSWORD_TOKEN,
DESCRIBE_TOKEN,
// Operators (still from pascal and not CQL3)

    PLUS_TOKEN,
    MOINS_TOKEN,
    ETOILE_TOKEN,
    DIV_TOKEN,
    EG_TOKEN,
    INF_TOKEN,
    SUP_TOKEN,
    P_TOKEN,
    VIR_TOKEN,
    PO_TOKEN,
    PF_TOKEN,
    CROCHO_TOKEN,
    CROCHF_TOKEN,
    ACOLADO_TOKEN,
    ACOLADF_TOKEN,
    DEUXP_TOKEN,
    PV_TOKEN,
    CARET_TOKEN,
    AT_TOKEN,
    DOLLAR_TOKEN,
    HASHTAG_TOKEN,
    ANDSYM_TOKEN,
    PERCENT_TOKEN,
    INFEG_TOKEN,
    SUPEG_TOKEN,
	DIFF_TOKEN,
    COLONEQ_TOKEN,
    PLUSEQ_TOKEN,
    MINUSEQ_TOKEN,
    MULTEQ_TOKEN,
    DIVEQ_TOKEN,
    SINGLEQUOTE_TOKEN,
    DOUBLEQUOTE_TOKEN,
	BACKSLASH_TOKEN,
	PI_TOKEN,
// COMMENTS
	SINGLELINE_COMMENT_TOKEN,
	OTHER_SINGLELINE_COMMENT_TOKEN,
	START_MULTILINE_COMMENT_TOKEN,
	END_MULTILINE_COMMENT_TOKEN,

//NOTE: keep "END_MULTILINE_COMMENT" the last searchable item
// OTHERS

    IDENTIFIER_TOKEN,
	STRING_TOKEN,
	INT_TOKEN,
	FLOAT_TOKEN,
	UUID_TOKEN,
	BLOB_TOKEN,
	BOOLEAN_TOKEN,
    HEX_TOKEN,
	
    END_TOKEN,
    ERROR_TOKEN
};
