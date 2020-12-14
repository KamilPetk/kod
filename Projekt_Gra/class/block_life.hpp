struct BlockLife
{
public:
    BlockLife(){}
    ~BlockLife(){}
    void destruct_block(int& healt_block);
};

void BlockLife::destruct_block(int& healt_block)
{
    healt_block--;
    std::cout << healt_block << std::endl;
}
