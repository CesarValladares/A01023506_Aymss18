#include <iostream>
#include <string>
#include <list>

using namespace std;

class IVisitor;

class DocPart{
public:
    string text;
    virtual void accept(IVisitor*)=0;
};

template <class T>
class VisitorImplementation : public DocPart{
    void accept(IVisitor* visitor){
        visitor->accept(*T);
    }
}

class Text : public DocPart, VisitorImplementation<Text>{
public:
    void accept(IVisitor* visitor);

};

class HyperLink : public DocPart, VisitorImplementation<HyperLink>{
public:

    string URL;
    void accept(IVisitor* visitor);
};

class Bold : public DocPart, VisitorImplementation<Bold>{
public:
    void accept(IVisitor* visitor);

};

class IVisitor{
public:
    string out;
    virtual void visit (HyperLink)=0;
    virtual void visit (Text)=0;
    virtual void visit (Bold)=0;
};

class HTMLVisitor : public IVisitor{
public:
    void visit(HyperLink h){
        out += "<a = href='" + h.URL + "'>" + h.text + "</a>";
    }
    void visit(Text t){
        out += t.text;
    }
    void visit(Bold b){
        out += "<b>" + b.text + "</b>";
    }
};

class LatexVisitor : public IVisitor{
public:
    void visit(HyperLink h){
        out += "\\href{" + h.URL + "}{" + h.text + "}";
    }
    void visit(Text t){
        out += t.text;
    }
        void visit(Bold b){
        out += "\\textbf{" + b.text + "}";
    }
};

class TextVisitor : public IVisitor{
public:
    void visit(HyperLink h){
        out += h.text + " " + h.URL;
    }
    void visit(Text t){
        out += t.text +  " ";
    }
    void visit (Bold b){
        out += b.text + " ";
    }
};

/*void Text::accept(IVisitor* visitor){
    visitor->visit(*this);
}

void Bold::accept(IVisitor* visitor){
    visitor->visit(*this);
}

void HyperLink::accept(IVisitor* visitor){
    visitor->visit(*this);
}*/


class Document{
    public:
    list<DocPart*> docpart;
    void accept(IVisitor* visitor){
        for(DocPart*d : docpart){
            d->accept(visitor);
        }
    }
};

int main(){

    Document d;
    Text t;
    t.text = "visita";
    Bold t2;
    t2.text = "my";
    HyperLink t3;
    t3.text = "página";
    t3.URL = "http://www.google.com";
    d.docpart.push_back(&t);
    d.docpart.push_back(&t2);
    d.docpart.push_back(&t3);

    HTMLVisitor* htmlvisitor = new HTMLVisitor();
    d.accept(htmlvisitor);
    cout << htmlvisitor->out << endl;

    TextVisitor* textvisitor = new TextVisitor();
    d.accept(textvisitor);
    cout << textvisitor->out << endl;

    LatexVisitor* latexvisitor = new LatexVisitor();
    d.accept(latexvisitor);
    cout << latexvisitor->out << endl;


    return 0;
}
