import { UnControlled as CodeMirror } from 'react-codemirror2';
import 'codemirror/lib/codemirror.css';
import 'codemirror/theme/monokai.css';
import 'codemirror/mode/clike/clike'; // mode for C/C++/Java-like languages



const Editor = ({codemirrorRef}) => {

  return (
    <div id='myClass' className='flex flex-col w-full h-full px-6 py-1'>
      <CodeMirror
        ref={codemirrorRef}
        className='w-full overflow-x-hidden mt-2 bg-[#272822] text-white rounded-lg'
        options={{
          lineNumbers: true,
          theme: 'monokai',
          mode: 'text/x-csrc',
        }}
        
      />
    </div>
  );
}

export default Editor;
