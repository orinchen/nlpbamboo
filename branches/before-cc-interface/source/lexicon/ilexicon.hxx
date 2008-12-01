/*
 * Copyright (c) 2008, detrox@gmail.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY detrox@gmail.com ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL detrox@gmail.com BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef ILEXICON_HXX
#define ILEXICON_HXX

#include <cassert>
#include <cstdio>

class ILexicon {
protected:
	static void _export(const char *s, int val, void *arg) 
	{
		FILE *fp = (FILE *)arg;
		fprintf(fp, "%d %s\n", val, s);
	}
public:
	ILexicon() {};
	ILexicon(int size) {};
	ILexicon(const char *filename) {};

	virtual void insert(const char*, int val) = 0;
	virtual int search(const char *) = 0;
	virtual int operator[](const char *) = 0;
	virtual void save(const char *filename) = 0;
	virtual void read_from_text(const char *filename, bool verbose) = 0;
	virtual void write_to_text(const char *filename) = 0;
	virtual int max_value() = 0;
	virtual int min_value() = 0;
	virtual int sum_value() = 0;
	virtual int num_insert() = 0;
	virtual ~ILexicon() {};
};

#endif // ILEXICON_HXX