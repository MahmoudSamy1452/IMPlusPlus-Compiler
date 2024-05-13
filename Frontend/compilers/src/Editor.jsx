import { UnControlled as CodeMirror } from 'react-codemirror2';
import 'codemirror/lib/codemirror.css';
import 'codemirror/theme/monokai.css';
import 'codemirror/mode/clike/clike'; // mode for C/C++/Java-like languages

const Editor = ({title, readOnly, codemirrorRef}) => {

  return (
    <div className='flex flex-col justify-center w-full max-h-[50vh] p-10'>
      <h2 className='mt-5 text-2xl text-white font-bold text-center'>{title}</h2>
      <CodeMirror
        ref={codemirrorRef}
        className='w-full mt-5 bg-[#272822] text-white rounded-lg'
        options={{
          lineNumbers: true,
          theme: 'monokai',
          mode: 'text/x-csrc',
          readOnly: readOnly,
        }}
      />
    </div>
  );
}

export default Editor;