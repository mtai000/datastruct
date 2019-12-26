call plug#begin()
Plug 'tpope/vim-sensible'
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'ianding1/leetcode.vim'
call plug#end()

syntax on
filetype on

set ruler
set number
set autoindent

set ts=4
set expandtab
set hlsearch
set incsearch
set cindent shiftwidth=4 
