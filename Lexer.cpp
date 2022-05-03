import java.oo.*;


public class _lexer {

    private char ch = ' '; 
    private BufferedReader input;
    private String line = "";
    private int col = 1;
    private final String letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    private final char eolnCh = '\n';
    private final char eofCh = '\004';
    
    public Lexer(String fileName) { 
        try {
            input = new BufferedReader (new FileReader(fileName));
        }
        catch (FileNotFoundException e) {
            System.out.println("File not found: " + fileName);
            System.exit(1);
        }
    }

    private char nextChar() { 
        col++;
        if (col >= line.length()) {
            try {
                line = input.readLine( );
            } catch (IOException e) {
                System.err.println(e);
                System.exit(1);
            } 
            if (line == null) 
                line = "" + eofCh;
            else {
                line += eolnCh;
            } 
            col = 0;
        } 
        return line.charAt(col);
    }

    public String next( ) { 
        do {
			if (isLetter(ch)) { 
                String spelling = concat(letters);
                return spelling;
            } else switch (ch) {
            case ' ': 
            case '\t': 
            case '\r': 
            case eolnCh:
                ch = nextChar();
                break;
    
            case '(': ch = nextChar();
    			return "(";
            //Энд зарим шалгах ёстой дутуу токенуудыг нөхөж бичих
            case eofCh: return "eof";
            } 
        } while (true);
    } 

    private boolean isLetter(char c) {
        //үсэг мөн эсэхийг шалгаад bool утга буцаах кодыг нөхөж бич.
    	return false;
    }

    private String concat(String set) {
        String r = "";
        do {
            r += ch;
            ch = nextChar();
        } while (set.indexOf(ch) >= 0);
        return r;
    }

    private String isCSyntax() {
    	boolean syntax = true;
    	//Салгасан токенуудыг int, main, (, ), {, } дараалалтай байгаа эсэхийг шалгах
    	//кодыг нөхөж бич
    	if(syntax) {
    		return "dadaa";
    	} else {
    		return "СИ код биш";	
    	}
    }
    
 