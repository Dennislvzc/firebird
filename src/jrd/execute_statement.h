/*
 *	PROGRAM:	JRD Access Method
 *	MODULE:		execute_statement.h
 *	DESCRIPTION:	Dynamic SQL statements execution
 *
 *  The contents of this file are subject to the Initial
 *  Developer's Public License Version 1.0 (the "License");
 *  you may not use this file except in compliance with the
 *  License. You may obtain a copy of the License at
 *  http://www.ibphoenix.com/main.nfs?a=ibphoenix&page=ibp_idpl.
 *
 *  Software distributed under the License is distributed AS IS,
 *  WITHOUT WARRANTY OF ANY KIND, either express or implied.
 *  See the License for the specific language governing rights
 *  and limitations under the License.
 *
 *  The Original Code was created by Alexander Peshkoff
 *  for the Firebird Open Source RDBMS project.
 *
 *  Copyright (c) 2003 Alexander Peshkoff <peshkoff@mail.ru>
 *  and all contributors signed below.
 *
 *  All Rights Reserved.
 *  Contributor(s): ______________________________________.
 */

#ifndef JRD_EXECUTE_STATEMENT_H
#define JRD_EXECUTE_STATEMENT_H

#include "../jrd/jrd_blks.h"
#include "../include/fb_blk.h"
#include "../include/fb_vector.h"
#include "../jrd/exe.h"
#include "../jrd/y_ref.h"
#include "../jrd/ibase.h"

#define MAX_CALLBACKS	50

class ExecuteStatement {
private:
	FRBRD	* Attachment;
	FRBRD	* Transaction;
	FRBRD	* Statement;
	XSQLDA	* Sqlda;
	SCHAR	* Buffer;
	bool	SingleMode;
	TEXT	* StartOfSqlOperator;
	XSQLDA	* MakeSqlda(thread_db* tdbb, SSHORT n);
	ISC_STATUS	ReMakeSqlda(ISC_STATUS *vector, thread_db* tdbb);
	ULONG	ParseSqlda(void);
public:
	void Open(thread_db* tdbb, jrd_nod* sql, SSHORT nVars, bool SingleTon);
	bool Fetch(thread_db* tdbb, jrd_nod** FirstVar);
	void Close(thread_db* tdbb);
};

#endif // JRD_EXECUTE_STATEMENT_H

