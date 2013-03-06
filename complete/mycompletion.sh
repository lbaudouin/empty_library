_my_function()
{
    local argc cur prev opts
    COMPREPLY=()

    argc=${COMP_CWORD}
    cur="${COMP_WORDS[argc]}"
    prev="${COMP_WORDS[argc-1]}"
    opts="-i -o -l -h --help -?"

    case $prev in 
	-i|-o)
	    COMPREPLY=( $(compgen -f -X "!*.+(jpg|JPG|jpeg|JPEG|png|PNG|bmp|BMP|ppm|PPM|pgm|PGM|tiff|TIFF)" $cur ) )   
	    COMPREPLY+=( $(compgen -d -S / $cur) )          
	    return 0
	    ;;
	-l)
	    COMPREPLY=( $(compgen -f -X "!*.+(txt,TXT)" $cur ) )   
	    COMPREPLY+=( $(compgen -d -S / $cur) )          
	    return 0
	    ;; 
    esac

    if [[ "$cur" == -* ]] ; then
	COMPREPLY=( $(compgen -W "$opts" -- $cur ) )         
	return 0
    fi

    COMPREPLY=( $opts )

}
complete -F _my_function MyExecutable
