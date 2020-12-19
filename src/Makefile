ANTLR4=java -Xmx500M -cp "/usr/local/lib/antlr-4.8-complete.jar:.:/home/ajainuary/acad/compiler/antlr/antlr-4.8-complete.jar" org.antlr.v4.Tool

antlr:	minic.g4
		$(ANTLR4) -Dlanguage=Cpp -no-listener -visitor minic.g4
		# g++ -g main.cpp -o minic -I/usr/local/include/antlr4-runtime -lantlr4-runtime -I/media/ajainuary/EXT4A/llvm-release/include -std=c++14 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/media/ajainuary/EXT4A/llvm-release/lib -lLLVMCore -lLLVMRemarks -lLLVMBitstreamReader -lLLVMBinaryFormat -lLLVMSupport -lLLVMDemangle -lz -lrt -ldl -ltinfo -lpthread -lm -lxml2 -o codegen
		g++ -g main.cpp -o minic -I/usr/local/include/antlr4-runtime -lantlr4-runtime -I/media/ajainuary/EXT4A/llvm/install/clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04/include -std=c++14 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/media/ajainuary/EXT4A/llvm/install/clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04/lib -lLLVMCore -lLLVMRemarks -lLLVMBitstreamReader -lLLVMBinaryFormat -lLLVMSupport -lLLVMDemangle -lz -lrt -ldl -ltinfo -lpthread -lm -lxml2 -o codegen

clean:	
		rm -f minicLexer.h minicParser.h minic *.tokens *.interp minicBaseVisitor.cpp \
		rm -f minicBaseVisitor.h minicParser.cpp minicLexer.cpp minicBaseVisitor.cpp  \ 
		rm -f minicVisitor.cpp  minicVisitor.h
