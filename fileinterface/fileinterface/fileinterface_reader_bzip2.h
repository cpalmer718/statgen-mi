/*
  Copyright 2015 Cameron Palmer

  This file is part of statgen-mi.
  
  statgen-mi is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  statgen-mi is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with statgen-mi.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __MI_FILEINTERFACE_FILEINTERFACE_READER_BZIP2_H__
#define __MI_FILEINTERFACE_FILEINTERFACE_READER_BZIP2_H__

#include "fileinterface/config.h"
#ifdef FILEINTERFACE_HAVE_LIBBZ2
#include "fileinterface/fileinterface_reader_parent.h"

#include <string>
#include <cstdlib>
#include <stdexcept>
#include <cstdio>
#include <bzlib.h>

namespace MI {
  class fileinterface_reader_bzip2 : public fileinterface_reader {
  public:
    fileinterface_reader_bzip2();
    ~fileinterface_reader_bzip2() throw() {close(); delete [] _buf;}
    
    void open(const char *filename);
    void close();
    void clear();
    bool is_open() const;
    char get();
    bool getline(std::string &);
    bool eof() const;
    bool good() const;
    bool bad() const;
    void read(char *, std::streamsize);
  protected:
    void refresh_buffer();
  private:
    FILE *_raw_input;
    BZFILE *_bz_input;
    bool _eof;
    char *_buf;
    unsigned _buf_max;
    unsigned _buf_read;
    unsigned _buf_remaining;
  };
}

#endif //FILEINTERFACE_HAVE_LIBBZ2

#endif //__MI_FILEINTERFACE_FILEINTERFACE_READER_BZIP2_H__
