//
// The MIT License (MIT)
//
// Copyright 2013-2014 The MilkCat Project Developers
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// milkcat_windows_test.cc --- Created at 2015-02-20
//
// NOTE: This file is GBK encoded
//

#include <milkcat.h>
#include <stdio.h>

using milkcat::Parser;

int main() {
  Parser::Options options;
  options.SetModelPath("data");
  options.UseGBK();

	Parser parser(options);
	Parser::Iterator it;
	if (parser.ok()) {
		parser.Predict(&it, "�ҵ�èϲ����ţ�̡�");
		while (it.Next()) {
			printf("%s/%s  ", it.word(), it.part_of_speech_tag());
		}
		putchar('\n');
	}
	else {
		printf("error: %s\n", milkcat::LastError());
	}
	return 0;
}